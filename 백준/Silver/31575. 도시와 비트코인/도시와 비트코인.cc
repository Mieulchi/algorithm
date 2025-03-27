#include <iostream>
using namespace std;

int n, m;
int arr[300][300];
int visited[300][300];
string ans = "No";

void dfs(int r, int c) {
	visited[r][c] = 1;
	if (r == n - 1 && c == m - 1) {
		ans = "Yes";
		return;
	}
	if (ans == "No") {
		if (r + 1 < n && arr[r + 1][c] && !visited[r + 1][c]) {
			dfs(r + 1, c);
		}
		if (c + 1 < m && arr[r][c + 1] && !visited[r][c + 1]) {
			dfs(r, c + 1);
		}
	}
}

void solve() {
	dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}