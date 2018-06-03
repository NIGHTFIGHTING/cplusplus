yum  install  yum-utils
yum  install  glibc
使用gdb调试需要编译中每一步-g

1.在调试多进程程序时，gdb默认只会追踪父进程的运行，而子进程会独立运行，gdb不会控制
2.
如果要同时调试父进程和子进程，可以使用“set detach-on-fork off”（默认detach-on-fork是on）命令，这样gdb就能同时调试父子进程，并且在调试一个进程时，另外一个进程处于挂起状态。
gdb 2开始调试进程
a.set detach-on-fork off
b.start
c.用“i inferiors”（i是info命令缩写）查看进程状态
d.前面显示“*”是正在调试的进程。当父进程退出后，用“inferior infno”切换到子进程去调试
3.如果想让父子进程都同时运行，可以使用“set schedule-multiple on”（默认schedule-multiple是off）命令
