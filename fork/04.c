#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>

using namespace std;

#if 0
进程的几种终止方式
(1)正常退出
   从main函数返回[return]
   调用exit
   调用_exit/_Exit
(2)异常退出
   调用abort   产生SIGABOUT信号
   由信号终止  Ctrl+C [SIGINT]
   ...(并不完全, 如return/pthread_exit等)
#endif

//尝试查看该程序的打印输出
int main()
{
    cout << "In main, pid = " << getpid();
    //去掉了endl；
    //原理：与终端关联，stdout为行缓冲，在文件中，为全缓冲；
    //详细信息请参考《UNIX环境高级编程》(第三版)8.5节, P188
    //exit(0);为C库函数，详细解释如下
    _exit(0);
}
