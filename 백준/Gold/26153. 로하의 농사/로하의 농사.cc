#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, m;
int arr[50][50];
int visited[50][50];
int x, y, p;
int ans;

//       0
//     3 x 1
//       2

void dfs(int r, int c, int from, int p, int v);

void init() {
	visited[x][y] = 1;
	dfs(x - 1, y, 0, p - 1, arr[x][y]);
	dfs(x, y + 1, 1, p - 1, arr[x][y]);
	dfs(x + 1, y, 2, p - 1, arr[x][y]);
	dfs(x, y - 1, 3, p - 1, arr[x][y]);
}

void dfs(int r, int c, int from, int p, int v) {
	if (visited[r][c] || r >= n || r < 0 || c >= m || c < 0 || p < 0) {
		return;
	}
	visited[r][c] = 1;

	v += arr[r][c];
	ans = max(ans, v);
	if (from == 0) {
		dfs(r - 1, c, 0, p - 1, v);
		dfs(r, c + 1, 1, p - 2, v);
		dfs(r, c - 1, 3, p - 2, v);
	}
	else if (from == 1) {
		dfs(r - 1, c, 0, p - 2, v);
		dfs(r, c + 1, 1, p - 1, v);
		dfs(r + 1, c, 2, p - 2, v);
	}
	else if (from == 2) {
		dfs(r, c + 1, 1, p - 2, v);
		dfs(r + 1, c, 2, p - 1, v);
		dfs(r, c - 1, 3, p - 2, v);
	}
	else {
		dfs(r - 1, c, 0, p - 2, v);
		dfs(r + 1, c, 2, p - 2, v);
		dfs(r, c - 1, 3, p - 1, v);
	}
	visited[r][c] = 0;
}

void solve() {
	ans = arr[x][y];
	init();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	cin >> x >> y >> p;
	solve();
	cout << ans;
}