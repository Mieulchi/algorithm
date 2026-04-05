#include <iostream>
#include <algorithm>
using namespace std;

#define INF -1

int n, m, ans;

// 가능한 상태 = 1(1), 3(2), 7(4), 15(0)
// dp[i][j] = i번째 자리에 j개 옷걸이 걸었을 때 걸 수 있는 최대 옷 개수

int dp[5001][10001];

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][1] = 1;
	dp[0][3] = 2;
	dp[0][7] = 4;
	dp[0][15] = 0;
	ans = max(ans, dp[0][m]);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i - 1][j] != INF && j + 1 <= m) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + 1);
			}
			if (dp[i - 1][j] != INF && j + 3 <= m) {
				dp[i][j + 3] = max(dp[i][j + 3], dp[i - 1][j] + 2);
			}
			if (dp[i - 1][j] != INF && j + 7 <= m) {
				dp[i][j + 7] = max(dp[i][j + 7], dp[i - 1][j] + 4);
			}
			if (dp[i - 1][j] != INF && j + 15 <= m) {
				dp[i][j + 15] = max(dp[i][j + 15], dp[i - 1][j]);
			}
			if (dp[i][m] != INF) {
				ans = max(ans, dp[i][m]);
			}
		}
	}
	if (!ans) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << ans;

}