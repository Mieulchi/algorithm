#include <iostream>
using namespace std;
#define MOD 1000000007

int n, e;
long long dp[501][501];
//sum[i][j] = i의 길이에서 j점이상인 함수 문자열의 갯수
long long sum[501][501];

void solve() {
    sum[1][0] = dp[1][0] = 1;
    sum[2][0] = sum[2][1] = dp[2][1] = 1;
    for (int i = 3; i <= n; i++) {
        //f
        for (int j = 1; j <= i - 2; ++j) {
            //j + t + 1 == i
            int t = i - 1 - j;
            for (int k = 0; k < i; ++k) {
                long long a = dp[j][k] % MOD;
                long long b = dp[t][k] % MOD;
                long long add = (a * (sum[t][k] % MOD) % MOD + (b * sum[j][k] % MOD) % MOD - ((a * b) % MOD)) % MOD;
                if (add < 0) {
                    add += MOD;
                }
                dp[i][k] += add;
                dp[i][k] %= MOD;
            }
        }
        //g
        for (int j = 1; j < n; ++j) {
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
        sum[i][i - 1] = dp[i][i - 1];
        for (int j = i - 2; j >= 0; --j) {
            sum[i][j] = (dp[i][j] + sum[i][j + 1]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    solve();
    cout << dp[n][e];
}