#include <iostream>
#include <vector>

using namespace std;

int fib(int N) {
    vector<int> dp(N+1, 0);
    if (N < 1) return 0;
    if (N <= 2) return 1;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[N];
}

int main(){
    for (int i=1; i<=20; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}