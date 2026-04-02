#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

typedef pair<int, int> pp;

int n, ans;
pp arr[501];

int dp[501][501];

void solve() {
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        dp[2][i] = arr[i].first * arr[i].second * arr[i + 1].second;
    }

    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            for (int k = j + 1; k <= i + j - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[k - j][j] + dp[i - k + j][k] + arr[j].first * arr[k].first * arr[j + i - 1].second);
            }
        }
    }

    ans = dp[n][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    solve();

    cout << ans;
}