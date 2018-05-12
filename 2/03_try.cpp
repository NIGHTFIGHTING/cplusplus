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
    }

};

class Obj {
public:
    Obj() {
        cout << "Obj ..." << endl;
    }
    Obj(const Obj& other) {
        cout << "Copy Obj ..." << endl;
    }
    ~Obj() {
        cout << "~Obj ..." << endl;
    }

};
class Test2 {
public:
    Test2() {
        cout << "Test2 ..." << endl;
        throw MyException("test exception");
    }
    Test2(const Test2& other) {
        cout << "Copy Test2 ..." << endl;
    }
    ~Test2() {
        cout << "~Test2 ..." << endl;
    }
private:
    Obj obj_;
};
int main() {
    try {  // try
        //Test t;
        //throw MyException("test exception");
        Test2 t2;
    } catch (MyException& e){  // catch
        cout << e.what() << endl;
    }
    return 0;
}
