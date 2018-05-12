#include <iostream>

#if 0
异常规格说明

1、异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。
可以在函数的声明中列出这个函数可能抛掷的所有异常类型。
例如：

void fun() throw(A，B，C，D);

2、若无异常接口声明，则此函数可以抛掷任何类型的异常。
3、不抛掷任何类型异常的函数声明如下：
#endif

void fun() throw();

using namespace std;

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
        throw MyExceptionD("test ExceptionD");
    }

}

void fun2() throw()
{

}

int main(void)
{
    try
    {
        fun(2);
    }

    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    }
    catch (MyExceptionD &e)
    {
        cout << "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    catch (MyException &e)
    {
        cout << "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

    return 0;
}
