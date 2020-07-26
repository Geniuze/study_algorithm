#include <stdio.h>
#include <vector>

using namespace std;

unsigned long long helper(vector<unsigned long long>& memo, int n) {
    if (n==1 || n==2) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) +
              helper(memo, n - 2);
    return memo[n];
}

unsigned long long fib(int N) {
    if (N < 1) return 0;
    
    vector<unsigned long long> memo(N+1,0);

    return helper(memo, N);
}

int main() {
    int i = 0;
    for (i=1; i<=20; i++) {
        printf("%lld ", fib(i));
    }
    printf("\n");
}