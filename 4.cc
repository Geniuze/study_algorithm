#include <iostream>


int fib(int N) {
    if (N < 1) return 0;
    if (N < 3) return 1;
    int priv =1, cur = 1;
    int sum = 0;
    for (int i = 3; i<=N; i++) {
        sum = priv + cur;
        priv = cur;
        cur = sum;
    }
    return sum;
}

int main() {
    for (int i = 1; i<=20 ; i++)
    {
        printf("%d ", fib(i));
    }
    printf("\n");
}
