#include <stdio.h>

int fib(int N) {
    if (N<=0) return 0;
    if (N==1 || N==2) return 1;
    return fib(N-1) + fib(N-2);
}

int main()
{
    int i = 0;
    for (i=1; i<=20; i++) {
        printf("%d ",fib(i));
    }
    printf("\n");

}