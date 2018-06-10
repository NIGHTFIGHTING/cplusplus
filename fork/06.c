#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>

using namespace std;

#if 0
终止处理程序：atexit
#include <stdlib.h>
int atexit(void (*function)(void));
#endif

//测试
void exitHandler1(void)
{
    cout << "If exit with exit, the function exitHandler will be called1" << endl;
}
void exitHandler2(void)
{
    cout << "If exit with exit, the function exitHandler will be called2" << endl;
}

int main()
{
    cout << "In main, pid = " << getpid() << endl;
    atexit(exitHandler1);	//注意，先注册的后执行
    atexit(exitHandler2);
    //exit(0);
    abort();
}
