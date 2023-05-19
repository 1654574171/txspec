## 日志系统
**Untrusted部分统一使用 C++ spdlog 日志库**  
reference: https://github.com/gabime/spdlog    
**Trusted部分暂时还未确定解决方案**  

### 使用方法
目前 Compliance-engine 仓库的编译过程中已经编译链接了 spdlog 库， 在项目中使用时只需要直接引用头文件:  
```C
// 使用已注册的 logger 时
#include <spdlog/spdlog.h>

// 注册新 logger 时，另外还需要包含这些头文件
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/....> // 取决于具体要声明什么 logger，参考 https://github.com/gabime/spdlog 
```

### 使用语法 
对于代码运行过程中产生的需要保存的日志文档，建议使用 spdlog 提供的 Rotating files 功能    

`compliance-engine/main.cpp`
```C
    // 注册了名字为 "ConsoleAndFile" 的组合 logger, 其中包含了向控制台输出的 logger 和向文件输出的 logger
    auto max_file_size = 1048576 * 5;
    auto max_files_num = 5;

    auto file_logger = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/data_server.txt", max_file_size, max_files_num, true);
    auto console_logger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>(); 
    spdlog::logger logger("current_file_name", {file_logger, console_logger});

    ...
    // 在任意地方调用该 logger
    spdlog::get("ConsoleAndFile")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
```

### 使用规范
Untrusted 部分的使用规范，可以参考 `data_access/server/DataServer.cpp`  
以下示例均来自于该文件
- 声明 logger 时，仅将其声明为文件内全局变量指针，或函数内局部变量，切勿声明为整个项目的全局变量(extern 关键字)
```C
// 头文件
#include <...>
...

spdlog::logger* spd_log;

// 函数部分
...
```
- 初始化 logger 时，将其名字赋值为当前文件的路径，方便查看打印 log 的具体位置
```C
    // 执行 compliance-engine 时，当前路径在 .../compliance_engine/build
    string cur_dir_name = get_current_dir_name();
    string cur_file_name = cur_dir_name.substr(0,cur_dir_name.rfind("/") + 1) + "data_access/server/DataServer.cpp";

    // 设置 logger 需要的参数
    auto max_file_size =  1024 * 1024 * 5;
    auto max_file_num = 5;
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("../logs/compliance_engine.txt", max_file_size, max_file_num);

    // 初始化 logger 
    spd_log = new spdlog::logger(cur_file_name, {console_sink, file_sink});
```
- 初始化 logger 时，将 log 日志的保存路径统一设置为 "../logs/compliance_engine.txt" (若有特殊需要，可以打印在别的文件中，但依然统一保存在 ../logs 文件夹下)
- 在函数内打印 log 时，为方便查看日志定位问题，建议在打印内容中写明当前函数名 (若打印内容不会产生混淆，也可以不必这么做)
> \*Function Name\*
```C
    DataServer::DataServer() {
        ...

        spd_log->info("*DataServer* Successfully setup spdlog");
        spd_log->info("*DataServer* Successfully construct a DataServer object");
    }
```