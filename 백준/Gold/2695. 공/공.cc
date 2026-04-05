#include <iostream>
#include <algorithm>
using namespace std;

int p, b, m, ans;

int dp[51][1001];

void solve() {
    for (int i = 1; i < 1001; ++i) {
        dp[1][i] = i;
    }
    for (int i = 2; i < 51; ++i) {
        dp[i][1] = 1;
        for (int j = 2; j < 1001; ++j) {
            dp[i][j] = 2002;
            for (int k = 1; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    cin >> p;
    while (p--) {
        cin >> b >> m;
        cout << dp[b][m] << '\n';
    }
}