// implicit conversion of classes:
#include <iostream>
using namespace std;

class A {};

class B {
public:
    // conversion from A (constructor):
    //explicit B (const A& x) {}
    B (const A& x) {}
    // conversion from A (assignment):
    B& operator= (const A& x) {return *this;}
    // conversion to A (type-cast operator)
    operator A() {return A();}
};

// 这个函数接受一个类型的参数B，但它也可以用一个类型A为object的对象来调用:fn(foo);
void fn (B arg) {}

int main ()
{
    A foo;
    B bar = foo;  // calls constructor
    bar = foo;  // calls assignment
    foo = bar;  // calls type-cast operator

    fn (foo);  // not allowed for explicit ctor
               // 标记为的构造函数explicit不能使用赋值语法来调用
               //bar不能用以下方法构造:B bar = foo;
    fn (bar);  

    return 0;
}
