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

void MyTerminate() {
    cout << "MyTerminate" << endl;
}

int main() {
    abort();
    //set_terminate(MyTerminate);
    try {  // try
        try {
            throw MyException("test exception");
        } catch (int) {
            cout << "Inner ..." << endl;
            cout << "catch a int exception" << endl;
        } /*catch (MyException& e){  // catch
            cout << "Outer ..." << endl;
            cout << e.what() << endl;
            throw e;
        }*/
    } catch (int) {
    }/*catch (MyException& e){  // catch
        cout << "Outer ..." << endl;
        cout << e.what() << endl;
    }*/
    return 0;
}
