#include <cstdio>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

// 获取UTF-8字符串的字符个数（注意，不是字符串长度哦）的代码：
size_t get_utf8_length(const std::string &input) {
    size_t length = 0;
    for (size_t i = 0, len = 0; i != input.length(); i += len) {
         unsigned char byte = input[i];
         if (byte >= 0xFC) // lenght 6
             len = 6;
         else if (byte >= 0xF8)
             len = 5;
         else if (byte >= 0xF0)
             len = 4;
         else if (byte >= 0xE0)
             len = 3;
         else if (byte >= 0xC0)
             len = 2;
         else
             len = 1;
         length ++;
    }
     return length;
}

// 把UTF-8编码的字符串拆分成单字集合，代码如下：
size_t utf8_to_charset(const std::string &input, std::vector<std::string> &output) {
    std::string ch;
    for (size_t i = 0, len = 0; i != input.length(); i += len) {
        unsigned char byte = (unsigned)input[i];
        if (byte >= 0xFC) // lenght 6
            len = 6;
        else if (byte >= 0xF8)
            len = 5;
        else if (byte >= 0xF0)
            len = 4;
        else if (byte >= 0xE0)
            len = 3;
        else if (byte >= 0xC0)
            len = 2;
        else
            len = 1;
        ch = input.substr(i, len);
        output.push_back(ch);
    }
    return output.size();
}

int main() {
    std::string str("你好么,asdad哈哈");
    cout << str.size() << endl;
    std::vector<std::string> output;
    utf8_to_charset(str, output);
    for (auto ite = output.begin(); ite != output.end(); ++ite) {
        std::cout << *ite << std::endl;

    }
    cout << get_utf8_length(str) << endl;
}
