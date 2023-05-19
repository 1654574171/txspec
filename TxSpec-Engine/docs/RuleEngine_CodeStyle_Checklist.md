# RuleEngine Code Style Checklist 代码审计

## 1. 头文件

- 使用 `#pragma once` 取代 `#ifdef`
- 项目内头文件中的引用应根据项目内源码目录树结构，避免使用 Linux 特性快捷目录  
  
    ```C
    #include "data_access/server/DataServer.h"       // Correct
    #include "../../data_access/server/DataServer.h" // Wrong
    ```

- 包含头文件顺序应为：
    1. 本源文件实现或测试的 `.h` 文件
    2. C 系统文件
    3. C++ 系统文件
    4. 其他库的 `.h` 文件
    5. 本项目的 `.h` 文件  
    
  - Example  
          
        ```C
        // C 系统文件
        #include <cstdlib>
        // C++ 系统文件
        #include <iostream>
        ...
        // 其他库的 .h 文件
        #include <grpcpp/grpcpp.h>
        ...
        // 本项目的 .h 文件
        #include "ThreadPool.h"
        ...
        ```
        
  - 头文件路径：  
  
    1. 除`third_party`和`protos`外，模块中需要对外部模块暴露的头文件统一放置在include目录下对应的文件夹：
    
    ```
    ├── common
    │   ├── base64
    │   ├── data_types
    │   │   ├── binding
    │   │   ├── data_access
    │   │   ├── key_management
    │   │   ├── local_attestation
    │   │   ├── request_processor
    │   │   └── rule_check
    │   ├── json_lib
    │   ├── local_attestation
    │   │   └── trusted
    │   ├── monitor
    │   │   ├── prometheus_client
    │   │   ├── trusted
    │   │   └── untrusted
    │   ├── remote_attestation
    │   │   └── untrusted
    │   └── utils
    │       └── untrusted
    ├── compliance_engine_server
    │   └── request_processor
    ├── http_client
    ├── key_management
    └── rule    
    ```
    
    2. 模块内头文件的引用路径从模块的根目录开始
    ```
    ├── trusted
    │   ├── binding_language
    │   │   ├── antlr4_generated
    │   │   └── binding_language_listener
    │   ├── local_attestation
    │   └── test_utils
    └── untrusted
    ```
    
    `binding_language_listener`中的文件想要引用`antlr4_generated`的文件，引用路径为：
    
    ```
    #include "trusted/binding_language/antlr4_generated/BindingLexer.h"
    ```

    3. 模块外头文件的引用路径从项目根目录下的include文件夹开始
    
    ```
    #include "common/json_lib/json11.hpp" 
    ```
    
    4. third_party的头文件，从具体项目的include或根目录下开始
    
    ```
    #include "spdlog/spdlog.h"
    ```
    
    5. protos的头文件，从*_cpp目录下开始
    
    ```
    #include "e2e_message/Signature.pb.h" // for trusted_cpp

    or

    #include "BindingQuery.pb.h"  // for untrusted_cpp
    ```
 
- 头文件中不要使用 using namespace 指定命名空间，否则会污染所有引用了该头文件的文件。在 cpp 文件中使用 using namespace  

## 2. 变量作用域

- 函数局部变量尽可能至于最小作用域内，并在变量声明时进行初始化
- if、while、for语句的变量应当在这些语句中声明，这样这些变量的作用域就限制在这些语句中
- 如果变量是一个对象，每次进入作用域会调用构造函数，离开作用域会调用析构函数，降低执行效率。此时推荐在语句外声明变量

    ```C
    // 每循环一次，都要构造、析构对象 p
    for (int i = 0; i < n; i++) {
        Person p = persons[i];
        ...
    }

    // 这种情况下推荐这样写
    Person p = Person();
    for (int i = 0; i < n; i++) {
        p = persons[i];
        ...
    }
    ```

- 静态生存周期的变量类型都必须是原生数据类型：int、float 和 char，以及原生数据类型的指针、数组和结构体  
    静态生存周期：对象的存储在程序开始时分配，在程序结束时解分配。对象只存在一个实例  
    静态生存周期的变量包括：全局变量、静态变量、函数静态变量、静态类成员变量

## 3. 类 VS 结构体

- 仅当只有数据成员时使用结构体，其他情况均使用类。所有数据成员应声明为 private
- 不要在构造函数中调用虚函数, 也不要在无法报出错误时进行可能失败的初始化。 若初始化可能失败，尽可能打印出失败原因  
- 类定义一般应以 public: 开始, 后跟 protected:, 最后是 private:

    ```C
    class Test {
        public:
            int a;
        protected:
            float b;
        private:
            char c;
    }
    ```

## 4. 函数参数

- 函数的参数顺序为: 输入参数在先, 后跟输出参数（需要从当前函数的执行中得到多个返回结果时，且输出参数为指针或引用）。当只需要一个返回结果时，可以使用Return返回值

    ```C
    // 通过执行以下函数，我们需要同时知道 grpc::Status 和 RegisterInfo* response 两个信息。此时需要注意参数顺序。
    string grpc::Status GetRegisterInfo(::grpc::ServerContext* context, const ::request_proto::RegisterReq* request, ::request_proto::RegisterInfo* response) override;

    // 通过执行以下函数，我们只需要得到 string 类型的执行结果
    string DataServer::GetEntity(...);
    ```

- 统一参数风格：输入参数为 const 引用(特殊情况，使用 const 指针)，输出参数为指针常量
    ```C
    // 简单例子
    // 输入参数 a 和 b, 输出参数为 c 
    bool TestAdd(const int& a, const int& b, int *const c)
    ```

    引用与指针的区别：
    > 指针可以为空，引用不能为空；  
    > 声明引用时必须初始化，且之后不可以再赋值；
    > 指针本身也需要占用空间，而引用不需要，它只是相当于变量的别名
    
    `const type *` 与 `type *const` 的区别：
    > `const type *` 表示指针指向的内容不可改变，但指针可以指向任意地址
    > `type *const` 表示指针指向的内同可以改变，但指针不能再指向其他地址了  

## 5. 注释

注释部分尽量写英文，避免切换编辑器、操作系统时产生乱码的情况。以下讲解内容为了和注释的风格统一，也使用英文描述。  

### Comment Syntax

- Use // instead of /**/, as long as you are consistent.

### Don't

**Do not state the obvious. In particular, don't literally describe what code does, unless the behavior is nonobvious to a reader who understands C++ well. Instead, provide higher level comments that describe why the code does what it does, or make the code self describing.**  
(self describing means that you name your variables, classes, functions properly, in a human-readable way)  

### File Comments

Files should start with file comments, except for those only declares, implements, or tests exactly one abstraction this documented by a comment at the point of declaration.

- License, for examplem Apache 2.0, BSD, LGPL, GPL
- We don't need to add author line currently, since everyone may make changes to every file. Consider it later.
- File Contents. The file-level coomment should broadly describe the contents of the file, and how the abstractions are related. One or two sentences are enough. DO NOT duplicate comments in both the `.h` and `.cpp` files.

#### Example of File Comments

`data_access/server/DataServer.h`

```C
// LICENSE: Apache 2.0 
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
// 
// This file declares class DataServer, 
// and defines SQL statements for table creation.   
```

`data_access/server/DataServer.cpp`

```C
// LICENSE: Apache 2.0 
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
// 
// This file implements class DataServer.
```

### Class Comments

- The class comment should provide the reader with enough information to know how and when to use the class, as well as any additional considerations necessary to correctly use the class.  
*If an instance of the class can be accessed by multiple threads, take extra care to document the rules and invariants surrounding multithreaded use.
**comments describing the use of the class should go together with its interface definition; comments about the class operation and implementation should accompany the implementation of the class's methods.**

#### Example of Class Comments

`data_access/server/DataServer.h`

```C
// DataServer is used to connect with MySQL database,
// and provides APIs to query data from tables.
// Example of usage:
//   DataServer *test = new DataServer();
//   test->Init("");
//   test->ConnectToDB();
//   // setup vector<string> cols
//   ...
//   //setup vector<data_access_proto::OcallContraint*> constraints
//   ...
//   test->QueryEntity("mychannel", "oxtoken", "transfer", cols, constraints, "", ""); 
class DataServer {
    ...
}
```

### Function Comments

Declaration comments describe use of the function (when it is non-obvious); comments at the definition of a function describe operation.

Comments at declaration should contain:  

- what the inputs and outputs are, should they be null or not;
- whether you allocates memory and free or not;
- if the function is re-entrant, what are its synchronization assumptions  

Comments at definition should

- focus on how it does, rather than copy from comments at declaration.

#### Example of Comments at Function Declarations

`data_access/util/Utils.h`

```C
// Example of usage: 
//   result = mysql_store_result(...);
//   vector<string> cols = ...;   
//   Json ret = InsertAllRowsInJSON(result, cols);
// Params: result: mysql query result data rows [N x M] NOT NULL;
//           cols: a vector of column name.
// Return: a Json object in such format:
//         {
//              "cols_1": [data11, data21, ..., dataN1],
//              "cols_2": [data12, data22, ..., dataN2],
//              ......
//              "cols_M": [data1M, datam2M, ..., dataNM]
//          }
Json InsertAllRowsInJSON(MYSQL_RES* result, vector<string> cols);
```

#### Example of Comments at Function Definitions

`data_access/util/Utils.cpp`

```C
// InsertAllRowsInJSON collects data rows [N x M] from MYSQL_RES, 
// iterates them and stores them into a map. 
// Finally, turn this map into Json object.
Json InsertAllRowsInJSON(MYSQL_RES* result, vector<string> cols) {
    ...
}
```

### Variable Comments

- In general the actual name of the variable should be descriptive enough to give a good idea of what the variable is used for. In certain cases, more comments are required.  
**Note: All global variables should have a comment describing what they are, what they are used for, and (if unclear) why it needs to be global.**

`binding/untrusted/ProcessTxRequest.cpp`

```C
// Explain what is kMaxOutSize used for?
extern uint64_t kMaxOutSize;
```

- **Note: The purpose of each class member variable must be clear (if not clearly expressed by name and type). In particular, add comments to describe the existence and meaning of sentinel values, such as nullptr or -1, when they are not obvious.**  

`data_access/server/DataServer.h`

```C
class DataServer {
    private:
        // database_type_ = "mysql", since we only support "mysql" currently.
        string database_type_;
}
```

### Implementation Comments

- In your implementation you should have comments in tricky, non-obvious, interesting, or important parts of your code.  

`data_access/server/DataServer.cpp`

```C
string DataServer::GetEntity(...) {
    ...

    // Typical way to free a char* array
    delete []sql;
    sql = NULL;
}
```

### TODO Comments

- Use TODO comments for code that is temporary, a short-term solution, or good-enough but not perfect.
TODOs should include the string TODO in all caps, followed by the name, e-mail address, bug ID, or other identifier of the person or issue with the best context about the problem referenced by the TODO.  
If your TODO is of the form "At a future date do something" make sure that you either include a very specific date ("Fix by November 2005") or a very specific event ("Remove this code when all clients can handle XML responses.").  

`data_access/server/DataServer.cpp`

```C
string DataServer::GetEntity(...) {
    ...
    // TODO (Xufei, fix by Sept 2021): The length of char array is pre-set. Make it flexible. Try to ues string. 
    char* sql = new char[2048];
}
```

## 6. 格式

- 使用制表符，建议在编译器里设置将制表符转为 4 个空格
- if 语句的写法:

    ```C
    if (condition) {
        do;
    }
    ```

- 指针和引用表达式，句点或箭头前后不要有空格. 指针/地址操作符 (*, &) 之后不能有空格  
- 在声明指针变量或参数时, 星号与类型或变量名之间的空格格式需要统一:

    ```C
    char* c;
    int& i;
    ```

- 类格式，关键词 public:, protected:, private: 要缩进 1 制表符 (4 个空格)

    ```C
    class Test {
        public:
            int a;
        private:
            char c;
    }
    ```

- 垂直留白越少越好，两个函数间的空行不要超过两个
- 每个代码逻辑段之间空行

    ```C
    // Do A
    ...

    // Do B
    ...
    ```

- 零值风格统一

    ```C
    int a = 0;
    float b = 0.0;
    char c = '\0';
    string d = "";
    AnyDataType* pointer = nullptr;
    ```

- 文件 / 文件夹的命名

```shell
——project
 |
 |-- lowercase_dir
     |
     |-- UpperCaseFile.cpp
 |
 |-- UpperCaseFile2.cpp
```

- 函数 / 变量的命名

```C
// 类名大写
class DataServer {
    public:
        // 函数名大写, 参数小写加下划线
        DataServer();
        ~DataServer();
        bool Init(string config_path);
    private:
        // 成员变量小写加下划线，并以下划线结尾
        string database_type_;
}

// 函数内局部变量小写加下划线
void Func (int input_param_1, int output_param_2) {
    int local_variable = 0;
}
```

## 7. C++ 特性

- 使用 C++ 的类型转换， 如 static_cast<>()， 不要使用 int y = (int)x 或 int y = int(x) 等转换方式  
- 对于迭代器和其他模板对象使用前缀形式的自增(++i)、自减(--i)运算符。理由是避免拷贝,提高效率
- 建议多使用 const 关键词。在确定变量不可被篡改情况下使用const

    ```C
    // 指针指向的内容不可篡改
    const int *p = 8;

    // 指针指向的地址不可篡改
    int a = 8;
    int* const p = &a;// 正确
    int b = 9;
    p = &b; // 错误

    // 指针指向的内容和地址均不可变
    int a = 8;
    const int * const  p = &a;
    ```

- sizeof 的使用。尽量使用sizeof(variable)，而不是sizeof(type)。但在不涉及任何变量的时候sizeof(type)可以接受  
- auto 的使用：auto修饰的变量会自动匹配成初始化表达式的类型。只能用于局部变量，不能用于文件作用域变量、命名空间作用域变量以及类成员变量  
- new 与 delete 一定是成对出现 (C++ 的自动回收仅限于在栈内，而 new 是在堆中开辟空间，需要手动释放)。new 与 delete 最好是在同一个函数中进行。  

    ```C
    Person *p = new Person();
    ...
    delete p;
    // delete 只是释放了内存空间，但指针仍然指向那块内存，会遗留野指针问题
    p = NULL;
    ```

    > delete 和 delete[] 有区别：  
    > 总结来说，  
    > new 单个对象时(包括自定义的 class，c++ 的 STL 等)，释放使用 delete;   
    > new 数组时，释放使用 delete[]  
    > Example:
    > ```C
    > // #1 new a single object
    > Obj *p1 = new Obj();
    > ...
    > delete p1;
    > p1 = NULL;
    >
    > // #2 new an array of object
    > Obj *p3 = new Obj[10]();
    > ...
    > delete[] p3;
    > p3 = NULL;
    >
    > // #3 new a vector of object. 
    > // ! Be careful when you using vector with your self-defined class object!
    > // Vector is also a class object, which would call its deconstruct function.
    > // Its deconstruct function would then call its element's deconstruct function, which may deconstruct a object twice.
    > // If you have to use vector to store your self-defined class object, please do as follows:
    > std::vector<DataServer*> p3;
    > p3.push_back(new DataServer());
    > ...
    > delete p3.at(i);
    > p3.at(i) = NULL;
    > // If you use vector to store original data type (char, int, float, string, ...), you can do as usual.
    > ```
- malloc 与 free 一定是成对出现。free 之后也需要将指针指向 NULL。malloc 与 free 最好是在同一个函数中进行。  
