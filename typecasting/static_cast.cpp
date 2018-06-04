#include <iostream>
#include <exception>
using namespace std;

class Base {};
class Derived: public Base {};

int main () {
    Base * a = new Base;
    Derived * b = static_cast<Derived*>(a);
    return 0;
}

#if 0
这将是有效的代码，虽然b会指向类的不完整对象，并且如果解除引用，可能会导致运行时错误。

因此，static_cast能够使用指向类的指针执行，不仅允许隐式允许的转换，而且还可以执行相反的转换。

#endif
