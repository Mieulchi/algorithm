#include <iostream>
#include <queue>
using namespace std;

int m, n;
int arr[500][500];
int visited[500][500];
int dp[500][500];
int ans;

int dfs(int r, int c) {
	if (r == m - 1 && c == n - 1) {
		return 1;
	}
	if (dp[r][c]) {
		return dp[r][c];
	}
	if (visited[r][c] && !dp[r][c]) {
		return 0;
	}
	visited[r][c] = 1;
	int cnt = 0;
	if (r + 1 < m && arr[r + 1][c] < arr[r][c]) {
		cnt += dfs(r + 1, c);
	}
	if (r - 1 >= 0 && arr[r - 1][c] < arr[r][c]) {
		cnt += dfs(r - 1, c);
	}
	if (c + 1 < n && arr[r][c + 1] < arr[r][c]) {
		cnt += dfs(r, c + 1);
	}
	if (c - 1 >= 0 && arr[r][c - 1] < arr[r][c]) {
		cnt += dfs(r, c - 1);
	}
	dp[r][c] = cnt;
	return cnt;
}

void solve() {
	ans = dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}