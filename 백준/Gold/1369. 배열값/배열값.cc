#include <iostream>
using namespace std;

#define INF 1000000007

int n;
int arr[1000][1000];
long long cnt[1000][1000][2];
long long dp[1000][1000][2];
int ans;

void count(int r, int c) {
    int cpy = arr[r][c];
    if (!cpy) {
        cnt[r][c][0] = cnt[r][c][1] = INF;
        return;
    }
    int cnt2 = 0, cnt5 = 0;
    while (true) {
        if (cpy % 5 == 0) {
            cpy /= 5;
            cnt5++;
        }
        else if (cpy % 2 == 0) {
            cpy /= 2;
            cnt2++;
        }
        else {
            break;
        }
    }
    cnt[r][c][0] = cnt2;
    cnt[r][c][1] = cnt5;
}

void solve() {
    count(0, 0);
    dp[0][0][0] = cnt[0][0][0];
    dp[0][0][1] = cnt[0][0][1];
    for (int i = 1; i < n; ++i) {
        count(0, i);
        dp[0][i][0] = dp[0][i - 1][0] + cnt[0][i][0];
        dp[0][i][1] = dp[0][i - 1][1] + cnt[0][i][1];
    }
    for (int i = 1; i < n; ++i) {
        count(i, 0);
        dp[i][0][0] = dp[i - 1][0][0] + cnt[i][0][0];
        dp[i][0][1] = dp[i - 1][0][1] + cnt[i][0][1];
        for (int j = 1; j < n; ++j) {
            count(i, j);
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + cnt[i][j][0];
            dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j - 1][1]) + cnt[i][j][1];
        }
    }
    ans = min(dp[n - 1][n - 1][0], dp[n - 1][n - 1][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    solve();
    cout << ans;
}