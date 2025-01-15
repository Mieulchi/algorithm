#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int trash[100][100];
int ans;
int visited[100][100];

queue<pair<int, int>> q;

void bfs(int r, int c) {
	int count = 0;
	q.push({ r, c });
	visited[r][c] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		count++;

		if (p.first - 1 >= 0 && trash[p.first - 1][p.second] && !visited[p.first - 1][p.second]) {
			q.push({ p.first - 1, p.second });
			visited[p.first - 1][p.second] = 1;
		}
		if (p.first + 1 < n && trash[p.first + 1][p.second] && !visited[p.first + 1][p.second]) {
			q.push({ p.first + 1, p.second });
			visited[p.first + 1][p.second] = 1;

		}
		if (p.second + 1 < m && trash[p.first][p.second + 1] && !visited[p.first][p.second + 1]) {
			q.push({ p.first, p.second + 1 });
			visited[p.first][p.second + 1] = 1;

		}
		if (p.second - 1 >= 0 && trash[p.first][p.second - 1] && !visited[p.first][p.second - 1]) {
			q.push({ p.first, p.second - 1 });
			visited[p.first][p.second - 1] = 1;

		}
	}

	if (count > ans) {
		ans = count;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (trash[i][j]) {
				bfs(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		trash[a - 1][b - 1] = 1;
	}

	solve();
	
	cout << ans;
}