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
2.为了控制这些类型的类之间的转换，我们有四个具体的转换符：dynamic_cast，reinterpret_cast，static_cast和const_cast。它们的格式是遵循尖括号（<>）和紧随其后的新类型，表达式在括号之间进行转换。
dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)
2.这些表达式的传统类型转换等效于,但每一个都有其特殊的特征：
(new_type) expression
new_type (expression)

四.dynamic_cast
1.dynamic_cast只能用于指针和类（或带void*）的引用。其目的是确保类型转换的结果指向目标指针类型的有效完整对象。
2.这自然包括指针上传（从指针到派生到指向基础的转换），其方式与隐式转换所允许的方式相同。
3.但是，当且仅当指向的对象是目标类型的有效完整对象时，dynamic_cast也可以向下转换（从指针到基地转换为指向派生的）多态类（具有虚拟成员的类）
4.当dynamic_cast不能转换指针时，因为它不是所需类的完整对象，它会返回一个空指针来指示失败。如果dynamic_cast用于转换为引用类型并且转换不可行，bad_cast则会抛出类型的异常。
5.dynamic_cast也可以执行指针允许的其他隐式转换,在指针类型（甚至在不相关的类之间）之间转换空指针,并将任何类型的任何指针转换为void *指针

五.
1.static_cast可以在指向相关类的指针之间执行转换，不仅是向上转换（从指针到派生指针到基址），还可以向下转换（从指针到基地指向派生指针）。运行时不执行任何检查，以确保被转换的对象实际上是目标类型的完整对象。因此，程序员应确保转换是安全的。另一方面，它不会产生类型安全检查的开销dynamic_cast
2.static_cast也能够隐式地执行所有允许的转换（不仅是那些指向类的指针），还能够执行与这些相反的操作。它可以：
转换void*为任何指针类型。在这种情况下，它保证如果void*通过从相同的指针类型转换获得该值，则得到的指针值是相同的。
将整数，浮点值和枚举类型转换为枚举类型。
3.static_cast还可以执行以下操作：
显式调用单参数构造函数或转换运算符。
转换为右值引用。
将enum class值转换为整数或浮点值。
将任何类型转换为void，评估并丢弃该值。

六.
1.reinterpret_cast的
reinterpret_cast将任何指针类型转换为任何其他指针类型，甚至是不相关的类。操作结果是从一个指针到另一个指针的值的简单二进制副本。所有指针转换都是允许的：既不指向内容也不检查指针类型本身。
它也可以投射指向整数类型的指针。此整数值表示指针的格式是特定于平台的。唯一的保证是转换为一个足够大的整数类型的指针可以完全包含它（例如intptr_t），保证能够被转换回有效的指针。

七.const_cast
1.这种类型的转换操纵指针所指向的对象的常量，可以被设置或被删除。例如，为了将const指针传递给需要非const参数的函数：

八.typeid
1.typeid允许检查表达式的类型:
typeid (expression)
2.此运算符返回对标准头<typeinfo>中定义的类型为type_info的常量对象的引用。 由typeid返回的值可以与使用operators ==和！=的typeid返回的另一个值进行比较，或者可以通过使用其name()成员来获得表示数据类型或类名的以null结尾的字符序列.
