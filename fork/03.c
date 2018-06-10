#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>

using namespace std;


#define ERR_EXIT(m) \
         do \
     {\
            perror(m);\
            exit(EXIT_FAILURE);\
         }while(0)

#if 0
文件共享
   父进程的所有文件描述符都被复制到子进程中, 就好像调用了dup函数, 父进程和子进程每个相同的打开文件描述符共享一个文件表项(因此, 父子进程共享同一个文件偏移量);
#endif

int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);

    int fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
        ERR_EXIT("file open error");

    cout << "We Don`t flash memory\n";
    fflush(stdout);

    char buf[BUFSIZ];
    bzero(buf, sizeof(buf));

    pid_t pid = fork();
    if (pid < 0)
        ERR_EXIT("fork error");
    else if (pid > 0)
    {
        strcpy(buf, "Parent...");
        write(fd, buf, strlen(buf));
        close(fd);
        cout << "fd = " << fd << endl;
        exit(0);
    }
    else if (pid == 0)
    {
        strcpy(buf, "Child...");
        write(fd, buf, strlen(buf));
        close(fd);
        cout << "fd = " << fd << endl;
        exit(0);
    }

    return 0;
}
