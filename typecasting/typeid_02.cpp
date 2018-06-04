// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;

class Base { virtual void f(){} };
class Derived : public Base {};

int main () {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    Derived* c = new Derived;
    Derived* d = NULL;
    // 注意，类型如何typeid考虑为指针是指针类型本身（包括a和b是类型class Base *）。但是，何时typeid应用于对象（如*a和*b）会typeid产生它们的动态类型（即它们的派生最完整对象的类型）。
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
    cout << "c is: " << typeid(c).name() << '\n';
    cout << "*c is: " << typeid(*c).name() << '\n';

    //如果typeid评估的类型是一个指向解引用操作符（*）的指针，并且此指针具有空值，则会typeid引发bad_typeid异常。
    cout << "d is: " << typeid(d).name() << '\n';
    cout << "*d is: " << typeid(*d).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}

#if 0
当typeid应用于类时，typeid使用RTTI来跟踪动态对象的类型。当typeid将其应用于其类型为多态类的表达式时，结果为最大派生完整对象的类型.
注：成员返回的字符串name的type_info依赖于具体的实现你的编译器和库。它不一定是具有典型类型名称的简单字符串，就像用于生成此输出的编译器一样。 
#endif
