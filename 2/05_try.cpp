#include <stdio.h>
#include <stdlib.h>
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


class Test {
public:
    Test() {
        cout << "Test ..." << endl;
    }
    Test(const Test& other) {
        cout << "Copy Test ..." << endl;
    }
    ~Test() {
        cout << "~Test ..." << endl;
        // 在析构函数中抛出异常
        throw 4;
    }

};

int main() {
    try {  // try
        Test t;
        throw MyException("test exception");
        // 先执行t的析构函数
        // 由于t析构函数中,抛出异常
    } catch (MyException& e){  // catch
        cout << e.what() << endl;
    } catch (int) {
        cout << "catch int exception" << endl;
    }
    return 0;
}
