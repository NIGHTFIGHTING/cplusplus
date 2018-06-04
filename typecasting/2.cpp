// class type-casting
// 这些通用形式的类型转换功能足以满足大多数基本数据类型的需求。但是，这些运算符可以不加区分地应用于类和指向类的指针，这会导致代码在语法上正确的时候会导致运行时错误。例如，下面的代码编译没有错误
#include <iostream>
using namespace std;

class Dummy {
    double i,j;
};

class Addition {
    int x,y;
public:
    Addition (int a, int b) { x=a; y=b; }
    int result() { return x+y;}
};

int main () {
    Dummy d;
    Addition * padd;
    // 程序声明了一个指针Addition，但是它使用显式的类型转换为它指定了另一个不相关类型的对象
    // 无限制显式类型转换允许将任何指针转换为任何其他指针类型，而与指向的类型无关。随后对成员的调用result将产生运行时错误或其他意外结果
    padd = (Addition*) &d;
    cout << padd->result();
    return 0;
}
