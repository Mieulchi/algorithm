#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000][1000];
int dp[1000][1000];
int fdp[1000][1000];
int bdp[1000][1000];
int ans;

void solve() {
	dp[0][0] = arr[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = dp[i - 1][j] + arr[i][j];
		}
		fdp[i][0] = dp[i][0];
		for (int j = 1; j < m; j++) {
			fdp[i][j] = max(dp[i][j], fdp[i][j - 1] + arr[i][j]);
		}
		bdp[i][m - 1] = dp[i][m - 1];
		for (int j = m - 2; j >= 0; j--) {
			bdp[i][j] = max(dp[i][j], bdp[i][j + 1] + arr[i][j]);
		}
		for (int j = 0; j < m; j++) {
			dp[i][j] = max({ dp[i][j], fdp[i][j], bdp[i][j] });
		}
	}
	ans = dp[n - 1][m - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}