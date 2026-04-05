#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pp;

int n, m, total;

pp arr[101];
//dp[i] = i명 썼을 때 점수차이 (내 점수 - 상대 점수)

int dp[100001];
string ans;

void solve() {
    for (int i = 100000; i >= 0; --i) {
        dp[i] = -total;
    }

    for (int i = 1; i <= n; ++i) {
        int s = arr[i].first;
        int p = arr[i].second;
        for (int j = 100000; j >= 0; --j) {
            if (j <= m && j - p - 1 >= 0 && dp[j - p - 1] != -1) {
                dp[j] = max(dp[j], dp[j - p - 1] + s * 2);
            }
            if (j <= m && j - p >= 0 && dp[j - p] != -1) {
                dp[j] = max(dp[j], dp[j - p] + s);
            }
        }
        if (p <= m) {
            dp[p] = max(dp[p], -total + s);
        }
        if (p + 1 <= m) {
            dp[p + 1] = max(dp[p + 1], -total + s * 2);
        }
    }

    int mx = -total;
    for (int i = 100000; i >= 0; --i) {
        mx = max(mx, dp[i]);
    }
    if (mx > 0) {
        ans = "W";
    }
    else if (mx < 0) {
        ans = "L";
    }
    else {
        ans = "D";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        total += arr[i].first;
    }

    solve();

    cout << ans;
}