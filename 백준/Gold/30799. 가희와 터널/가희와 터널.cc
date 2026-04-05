#include <iostream>
using namespace std;

#define MOD 998244353 

int s;
long long dp[50300][8];

void solve() {
    dp[1][0] = 6;
    dp[1][1] = 1;
    for (int i = 2; i <= s; ++i) {
        dp[i][0] = (dp[i - 1][0] * 6) % MOD;
        for (int j = 1; j < 7; ++j) {
            if (j <= i) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * 6;
                dp[i][j] %= MOD;
            }
        }
        if (i > 6) {
            dp[i][7] = (dp[i - 1][6] + dp[i - 1][7] * 7) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    solve();
    cout << dp[s][7];
}