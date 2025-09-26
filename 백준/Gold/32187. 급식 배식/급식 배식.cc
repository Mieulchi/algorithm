#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long dp[100001][2];
vector<pair<int, int>> v[100001];
long long ans;

void solve() {
    for (int i = 0; i < n; ++i) {
        if (v[i].size()) {
            dp[0][1] = v[i][0].second;
            int j = 0;
            for (j = 1; j < v[i].size(); ++j) {
                long long h = v[i][j].second;
                if (v[i][j].first == v[i][j - 1].first + 1) {
                    if (j > 1) {
                        dp[j][1] = max(dp[j - 2][1], dp[j - 1][0]) + h;
                        dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);
                    }
                    else {
                        dp[j][1] = h;
                        dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);
                    }
                }
                else {
                    dp[j][1] = max(dp[j-1][0], dp[j - 1][1]) + h;
                    dp[j][0] = max(dp[j - 1][1], dp[j - 1][0]);
                }
            }
            ans += max(dp[j - 1][0], dp[j - 1][1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int l;
    for (int i = 0; i < m; ++i) {
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int a, b;
            cin >> a >> b;
            v[a - 1].push_back({ i, b });
        }
    }
    solve();
    cout << ans;
}