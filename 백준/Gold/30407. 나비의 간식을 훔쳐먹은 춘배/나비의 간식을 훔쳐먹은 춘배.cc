#include <iostream>
#include <algorithm>
using namespace std;

int N;
int H, D, K;
int ans;
int p[19];
int dp[19][69];

void solve() {
    ans = -20000;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < 65; k++) {
                dp[j][k] = -1;
            }
        }
        if (i) {
            dp[0][D] = max(dp[0][D], H - max(0, (p[0] - D) / 2));
            dp[0][D + K] = max(dp[0][D + K], H - max(0, (p[0] - D - K)));
        }
        else {
            dp[0][D] = max(dp[0][D], H - max(0, (p[0] - D)));
        }
        for (int j = 1; j < N; j++) {
            for (int k = 0; k < 65; k++) {
                if (dp[j - 1][k] > -1) {
                    if (j == i) {
                        dp[j][k] = dp[j - 1][k] - max(0, p[j] - k);
                    }
                    else if (j == i + 1) {
                        dp[j][k + K] = dp[j - 1][k];
                    }
                    else {
                        dp[j][k + K] = max(dp[j][k + K], dp[j - 1][k] - max(0, (p[j] - k - K)));
                        dp[j][k] = max(dp[j][k], dp[j - 1][k] - max(0, (p[j] - k) / 2));
                    }
                }
            }
        }
        for (int j = 0; j < 65; j++) {
            ans = max(ans, dp[N - 1][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> H >> D >> K;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    solve();
    if (ans <= 0) {
        ans = -1;
    }
    cout << ans;
}