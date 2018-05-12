#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

/**
 * 错误的抛出点与错误处理点相隔的距离比较远
 **/
double Divide(double a, double b) {
    if (b == 0.0) {
        longjmp(buf, 1);  // throw
        // 会跳转到setjmp
    } else {
        return a/b;
    }
}

int main() {
    int ret;
    ret = setjmp(buf);
    if (ret == 0) {  // try
        printf("division ...\n");
        //printf("a/b = %f\n", Divide(5.0, 1.0));
        printf("a/b = %f\n", Divide(5.0, 0.0));
    } else if (ret = 1) {  // catch
        printf("division by zero\n");
    }
    return 0;
}
