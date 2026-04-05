#include <iostream>
using namespace std;

#define INF 1000000007

int n, t;
int arr[1000];
int S, M, E;
int s[11], m[11], e[11];
int ans;
int dp[11][11][11];

void solve() {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 11; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        int from = arr[i] + 1, to = arr[i + 1];
        for (int j = 0; j <= S; ++j) {
            for (int k = 0; k <= M; ++k) {
                for (int l = 0; l <= E; ++l) {
                    if (dp[j][k][l] != INF) {
                        if (j + 1 <= S) {
                            int start = max(dp[j][k][l], from);
                            int end = start + s[j + 1];
                            if (end <= to) {
                                dp[j + 1][k][l] = min(dp[j + 1][k][l], end);
                                ans = max(ans, j + k + l + 1);
                            }
                        }
                        if (k + 1 <= M) {
                            int start = max(dp[j][k][l], from);
                            int end = start + m[k + 1];
                            if (end <= to) {
                                dp[j][k + 1][l] = min(dp[j][k + 1][l], end);
                                ans = max(ans, j + k + l + 1);
                            }
                        }
                        if (l + 1 <= E) {
                            int start = max(dp[j][k][l], from);
                            int end = start + e[l + 1];
                            if (end <= to) {
                                dp[j][k][l + 1] = min(dp[j][k][l + 1], end);
                                ans = max(ans, j + k + l + 1);
                            }
                        }

                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> S >> M >> E;
    for (int i = 1; i <= S; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= M; ++i) {
        cin >> m[i];
    }
    for (int i = 1; i <= E; ++i) {
        cin >> e[i];
    }
    solve();
    cout << ans;
}