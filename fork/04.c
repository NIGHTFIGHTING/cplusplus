#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>

using namespace std;

#if 0
���̵ļ�����ֹ��ʽ
(1)�����˳�
   ��main��������[return]
   ����exit
   ����_exit/_Exit
(2)�쳣�˳�
   ����abort   ����SIGABOUT�ź�
   ���ź���ֹ  Ctrl+C [SIGINT]
   ...(������ȫ, ��return/pthread_exit��)
#endif

//���Բ鿴�ó���Ĵ�ӡ���
int main()
{
    cout << "In main, pid = " << getpid();
    //ȥ����endl��
    //ԭ�����ն˹�����stdoutΪ�л��壬���ļ��У�Ϊȫ���壻
    //��ϸ��Ϣ��ο���UNIX�����߼���̡�(������)8.5��, P188
    //exit(0);ΪC�⺯������ϸ��������
    _exit(0);
}
