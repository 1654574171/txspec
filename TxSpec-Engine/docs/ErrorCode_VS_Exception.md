## 错误码处理机制
### 如何创建错误码
各模块根据自己代码情况，归总错误码  
错误码可以先统一放在 `common/data_types/${your_module_name}/ErrorType.h`
错误码声明样例：
```C
// data_access 模块中可能需要的错误码
enum ERROR_CODE {
    // Init 函数执行过程中可能会因为某原因终止，或提前结束，则声明
    kDATAACCESS_INIT_ERROR = 0,
    kDATAACCESS_CONNECTDB_ERROR = 1,
    kDATAACCESS_CREATETABLE_ERROR = 2,
    kDATAACCESS_QUERYRESULT_ERROR = 3,
    kDATAACCESS_QUERYINPUT_ERROR= 4
}
```
### 如何处理错误码

## 异常处理机制
错误码机制和异常处理机制的作用是同样的，Complian-engine 项目中统一使用 throw + try-catch 的异常处理机制  
**相比检查错误码并处理的机制，抛出异常处理的机制更加严格：是否处理错误码完全是开发者主观行为，但如果抛出的异常没有被处理，程序会报错终止**  
**另外，错误码机制需要设计函数的返回值为错误码(例如 int err)，这就需要我们改动绝大多数的函数定义**

### 如何加入异常处理机制
```C
#include <exception>
using namespace std;
void ThrowException() {
    // You can throw DIY exception message as exception
    throw "a exception can be a const char* object";
    // throw -1;
    // throw 0.0;
    // throw a self-defined class, which can contain more information.
}

void TestException() {
    // You can be prepared to catch different types of exceptions, but only one is in effective.
    try {
        ThrowException();
    } catch (int i) {
        do something
        // you can also throw current exception again to let outter caller know.
        throw;
    } catch (float f) {
        do something
    } catch (const char* c) {
        do something
    } catch (exception& e) {
        // catch C++ pre-defined exception class
        do something
        // you can print out exception
        cout << e.what() << endl;
    } catch (MyException& m) {
        do something
    } 

}
```
> C++ standard exceptions can be found here: https://www.runoob.com/cplusplus/cpp-exceptions-handling.html  

### 何处需要加入异常处理机制
**Note: throw 和 try-catch 必须要对应，否则就容易出现 throw 了异常但是没有被处理的情况，程序终止**
- 当代码需要报错 Error，甚至可能因此终止程序时
```C

```
