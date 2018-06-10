#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <signal.h>
#include <unistd.h>

using namespace std;


#define ERR_EXIT(m) \
         do \
     {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

#if 0
僵尸进程:

   如果子进程先退出，父进程还没退出，那么子进程必须等到父进程捕获到了子进程的退出状态才真正结束，否则这个时候子进程就成为僵尸进程。
#endif

//生成僵尸进程
int main(int argc, char *argv[])
{
    // 避免僵尸进程 
    signal(SIGCHLD, SIG_IGN);
    pid_t pid = fork();
    if (pid < 0)
        ERR_EXIT("fork error");
    else if (pid == 0)
        exit(0);
    else
    {
        sleep(50);
    }
    exit(0);
}
