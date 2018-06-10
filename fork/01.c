#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <unistd.h>

using namespace std;


#define ERR_EXIT(m) \
         do \
     {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

#if 0
孤儿进程:
   如果父进程先退出，子进程还没退出那么子进程的父进程将变为init进程。（注：任何一个进程都必须有父进程）
#endif

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid < 0)
        ERR_EXIT("fork error");
    else if (pid > 0)
        exit(0);
    else
    {
        sleep(10);
        cout << "Child, ppid = " << getppid() << endl;
    }
    exit(0);
}
