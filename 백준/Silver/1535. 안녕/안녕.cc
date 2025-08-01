#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[20];
int b[20];
int dp[20][101];
int ans;

void solve() {
    for (int i = 0; i < n; i++) {
        if (100 - a[i] > 0) {
            dp[i][100 - a[i]] = b[i];
        }
        if (i) {
            for (int j = 1; j < 101; j++) {
                if (dp[i - 1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    if (j - a[i] > 0) {
                        dp[i][j - a[i]] = max(dp[i][j - a[i]], dp[i - 1][j] + b[i]);
                    }
                }
            }
        }
    }
    for (int i = 100; i > 0; i--) {
        if (dp[n - 1][i] > ans) {
            ans = dp[n - 1][i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve();
    cout << ans;
}   