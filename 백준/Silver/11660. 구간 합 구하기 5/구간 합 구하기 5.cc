#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1025][1025];
int dp[1025][1025];
int ans;
void solve() {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + sum + arr[i][j];
            sum += arr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    solve();
    int x1, y1, x2, y2;
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans = dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2] - dp[x1 - 1][y1 - 1]);
        cout << ans << '\n';
    }
}