http://www.cplusplus.com/doc/tutorial/typecasting/

一·用类进行隐式转换
在类的世界中，可以通过三个成员函数来控制隐式转换：
1.单参数构造函数：允许从特定类型的隐式转换来初始化一个对象。
2.赋值运算符：允许从赋值中的特定类型进行隐式转换。
3.类型转换运算符：允许隐式转换为特定类型。类型转换运算符使用特定的语法：它使用operator关键字，后跟目标类型和一组空括号。请注意，返回类型是目标类型，因此在operator关键字之前未指定。

二.关键字explicit
1.在函数调用中，C ++允许为每个参数进行一次隐式转换

三.类型转换
1.C ++是一种强类型语言。许多转换，特别是那些暗示对值有不同解释的转换，都需要一个明确的转换，在C ++中称为类型转换。对于泛型类型转换有两种主要的语法：功能和类似c:
double x = 10.3;
int y;
y = int (x);    // functional notation
y = (int) x;    // c-like cast notation
2.为了控制这些类型的类之间的转换，我们有四个具体的转换符：dynamic_cast，reinterpret_cast，static_cast和const_cast。它们的格式是遵循尖括号（<>）和紧随其后的新类型，表达式在括号之间进行转换。 这些表达式的传统类型转换等效于： 但每一个都有其特殊的特征：
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)
