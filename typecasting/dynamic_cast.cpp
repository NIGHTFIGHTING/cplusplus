// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class Base { public :virtual void dummy() {} };
class Derived: public Base {
public:
    int a;
    virtual void dummy() {
        cout << "Derived dummy" << endl;
    } 
};

#if 0
兼容性说明：这种类型dynamic_cast需要运行时类型信息（RTTI）来跟踪动态类型。一些编译器支持这个功能作为默认禁用的选项。这需要启用运行时类型检查使用dynamic_cast正确使用这些类型。
#endif

int main () {
    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived * pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd==0) cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd==0) cout << "Null pointer on second type-cast.\n";

    } catch (exception& e) {cout << "Exception: " << e.what();}

    try {
        Derived derived;
        Base& base = derived;
        Derived& der = dynamic_cast<Derived&>(base);
        der.dummy();
        
        Base base1;
        Base& base2 = base1;
        // Exception: std::bad_cast
        Derived& der1 = dynamic_cast<Derived&>(base2);
        der1.dummy();
    } catch (exception& e) {cout << "Exception: " << e.what();}
    return 0;
}

#if 0
上面的代码尝试从类型为Base*（pba和pbb）的指针对象向类型的指针对象执行两次动态强制转换Derived*，但只有第一个成功。注意它们各自的初始化：
Base * pba = new Derived;
Base * pbb = new Base;
即使两者都是类型的指针Base*，pba实际上也指向类型的对象Derived，而pbb指向类型的对象Base。因此，当使用它们各自的类型转换时dynamic_cast，pba指向类的完整对象Derived，而pbb指向类的对象Base，该对象是类的不完整对象Derived。
当dynamic_cast不能转换指针时，因为它不是所需类的完整对象（如前例中的第二次转换），它会返回一个空指针来指示失败。如果dynamic_cast用于转换为引用类型并且转换不可行，bad_cast则会抛出类型的异常
#endif

