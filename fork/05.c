#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>

using namespace std;

#if 0
系统调用_exit直接陷入内核，而C语言库函数是经过一系列的系统清理工作，再调用Linux内核的;
小结:exit与_exit区别
   1）_exit是一个系统调用，exit是一个c库函数
   2）exit会执行清除I/O缓存
   3）exit会执行调用终止处理程序	//终止处理程序如下
#endif

int main()
{
    cout << "In main, pid = " << getpid();
    fflush(stdout);	//增加了刷新缓冲区工作
    _exit(0);
}
