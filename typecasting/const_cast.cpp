// const_cast
#include <iostream>
using namespace std;

void print (char * str)
{
    cout << str << '\n';
}

int main () {
    const char * c = "sample text";
    print ( const_cast<char *> (c) );
    return 0;
}

// 上面的例子可以保证工作，因为函数print不会写入指向的对象。请注意，删除指向对象的常量以实际写入它会导致未定义的行为。
