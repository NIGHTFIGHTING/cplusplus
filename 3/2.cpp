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


int main(void)
{
    try
    {
        //MyExceptionD e("test MyExceptionD"); 
        //throw &e;
        MyExceptionD* e = new MyExceptionD("test MyExceptionD"); 
        throw e;
    }

    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    } 
    #if 0
    catch (void* e)
    {
        // 还有一点是，任何类型的指针都能被void* 指针所捕获，如果将catch (void* e);注释打开，那么由于排在前面，异常首先将被它所捕获。
        cout<<"catch void* ..."<<endl;
        cout<<((MyExceptionD*)e)->what()<<endl;
        delete (MyExceptionD*)e;
    }
    #endif
    catch (MyExceptionD* e)
    {   // 派生类的异常处理器放在前面
        // 其中MyException, MyExeptionD类如上所示，现在MyExeptionD 对象是在堆上分配的，所以在catch 的时候还没释放，还可以访问到
        // e->what(); 但需要自己在catch 末尾delete e; 假设将 throw new MyExceptionD("test exception"); 换成
        // MyExceptionD e("test exception");
        // throw &e;
        // 即抛出局部对象的指针，由于在catch 时MyExeptionD 对象已经被析构了，所以访问不到e->what(); 即e是空悬指针。
        cout << "catch MyExceptionD ..." << endl;
        cout << e->what() << endl;
        delete e; // 堆的空间,需要释放
        e = nullptr;
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
