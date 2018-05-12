#include <iostream>
#include <exception>
using namespace std;

class MyException
{
public:
    MyException(const char *message)
        : message_(message)
    {
        cout << "MyException ..." << endl;
    }
    MyException(const MyException &other) : message_(other.message_)
    {
        cout << "Copy MyException ..." << endl;
    }
    virtual ~MyException()
    {
        cout << "~MyException ..." << endl;
    }

    const char *what() const
    {
        return message_.c_str();
    }
private:
    string message_;
};

class MyExceptionD : public MyException
{
public:
    MyExceptionD(const char *message)
        : MyException(message)
    {
        cout << "MyExceptionD ..." << endl;
    }
    MyExceptionD(const MyExceptionD &other)
        : MyException(other)
    {
        cout << "Copy MyExceptionD ..." << endl;
    }
    ~MyExceptionD()
    {
        cout << "~MyExceptionD ..." << endl;
    }
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
    if (n == 1)
    {
        throw 1;
    }
    else if (n == 2)
    {
        throw MyException("test Exception");
    }
    else if (n == 3)
    {
        MyExceptionD exception_d("test ExceptionD");
        throw exception_d;
        //throw MyExceptionD("test ExceptionD");
    }

}

void fun2() throw()
{

}

// 如果异常类型为C++的类，并且该类有其基类，则应该将派生类的错误处理程序放在前面，基类的错误处理程序放在后面
// 派生类的异常能够被基类所捕获，且前面的异常处理程序能够匹配的话首先catch，如果把基类的放在最前面，而且不是引用的形式，如 catch (MyException e); 那么将会被这个所catch 到，而且在构造e 的过程会有object slicing 的问题。
int main(void)
{
    try
    {
        //fun(2);
        fun(3);
    }

    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    } 
    catch (MyExceptionD e)
    {   // 派生类的异常处理器放在前面
        cout << "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    catch (MyException& e)
    {
        // Object slice对象切割
        //  抛出派生类对象,是能被基类异常处理器捕获的
        cout << "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

    return 0;
}
