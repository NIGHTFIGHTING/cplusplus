#include <iostream>

using namespace std;

//Perfect forwarding allows you to write a single function template
//that takes n arbitrary arguments and forwards them transprently to
//another arbitrary function. The nature of the argument (modifiable,
//const, lvalue or rvalue) is preserved in this forwarding process.
//
//template<typename T1, typename T2>
//void functionA(T1&& t1, T2&&t2) {
//    functionB(std::forward<T1>(t1)),
//            std::forward<T2>(t2));
//}

void process(int& i) {
    cout << "process(int&):" << i << endl;
}

void process(int&& i) {
    cout << "process(int&&):" << i << endl;
}

void forward(int&& i) {
    cout << "forward(int&&):" << i << endl;
    process(std::forward<int>(i));
}

int main() {
    int a = 0;
    process(a);

    process(1);

    process(move(a));

    forward(2);

    forward(move(a));
    return 0;
}
