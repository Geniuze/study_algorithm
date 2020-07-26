#include <iostream>
#include <vector>

using namespace std;

/* error algorithm */
int dp( int *coin_list, int coin_count, int mount) {
    int res = 0;
    int max = 0;
    if (mount < 0) return -1;
    if (mount == 0) return 0;

    for (int i = 0; i<coin_count; i++) {
        if (coin_list[i] <= mount && max < coin_list[i]) {
            max = coin_list[i];
        }
    }
    if (max == 0) return 0;
    return 1 + dp(coin_list, coin_count, mount - max);
}

int dp1(int *coin_list, int coin_count, int mount, vector<int> & memo) {
    int res = 0x7fffffff;
    if (mount == 0) return 0;
    if (mount < 0 ) return -1;

    if (memo[mount] != 0) return memo[mount];

    for (int i = 0; i<coin_count; i++) {
        int ress = dp1(coin_list, coin_count, mount-coin_list[i], memo);
        if (ress == -1) continue;
        res = res < ress + 1 ? res : ress + 1;
    }
    if (res == 0x7fffffff) return -1;
    memo[mount] = res;
    return res;
}

int coin_change(int *coin_list, int coin_count, int mount) {
    vector<int> memo(mount + 1, 0);
    return dp1(coin_list, coin_count, mount, memo);
}

int dp2(int *coin_list, int coin_count, int mount) {
    if (mount == 0) return 0;
    if (mount < 0) return -1;
    vector<int> dp(mount+1, mount+1);
    dp[0] = 0;
    for (int i = 0; i<dp.size(); i++) {
        for (int j = 0; j < coin_count; j++) {
            if (i - coin_list[j] < 0) continue;
            dp[i] = dp[i] < (1 + dp[i-coin_list[j]]) ? dp[i] : (1+dp[i-coin_list[j]]);
        }
    }
    return dp[mount];
}

int main() {
    int coin_list[] = {1, 2, 5};
    int mount = 1001;
    printf("dp = %d\n", dp2(coin_list, sizeof(coin_list)/sizeof(int), mount));
    return 0;
}
