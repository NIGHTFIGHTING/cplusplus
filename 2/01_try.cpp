#include <stdio.h>
#include <setjmp.h>
#include <iostream>

using namespace std;

class MyException {
public:
    MyException(const char* message) : message_(message) {
        cout << "MyException ..." << endl;
    }
    MyException(const MyException& other): message_(other.message_) {
        cout << "Copy MyException ..." << endl;
    }
    ~MyException() {
        cout << "~MyException ..." << endl;
    }
    const char* what() const {
        return message_.c_str();
    }

private:
    string message_;
};

/**
 * 错误的抛出点与错误处理点相隔的距离比较远
 **/
double Divide(double a, double b) {
    if (b == 0.0) {
        //MyException e("division by zero");
        //throw e;  // throw调用拷贝构造函数
        throw MyException("division by zero");
        // throw 1;
    } else {
        return a/b;
    }
}

int main() {
    try {  // try
        printf("division ...\n");
        //printf("a/b = %f\n", Divide(5.0, 1.0));
        //printf("a/b = %f\n", Divide(5.0, 0.0));
        printf("a/b = %f\n", Divide(5.0, 1.0));
        printf("a/b = %f\n", Divide(5.0, 0.0));
        printf("a/b = %f\n", Divide(5.0, 0.0));
    } catch (int){  // catch
        printf("division by zero\n");
    } catch (MyException& e){  // catch
        cout << e.what() << endl;
    } catch (double) {
        cout << "double execption ..." << endl;
    } catch (...) {
        cout << "catch a execption ..." << endl;
    }
    return 0;
}
