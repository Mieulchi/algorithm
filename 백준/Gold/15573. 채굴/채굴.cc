#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[1000][1000];
int visited[1000][1000];
int ans;

void init() {
	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { visited[i][j] = 0; } }
}

int bfs(int d) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		if (arr[i][0] <= d) {
			q.push({ i, 0 });
		}
		if (arr[i][m - 1] <= d) {
			q.push({ i, m - 1 });
		}
	}
	for (int i = 0; i < m; i++) {
		if (arr[0][i] <= d) {
			q.push({ 0, i });
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> front = q.front();
			q.pop();
			int r = front.first;
			int c = front.second;
			if (!visited[r][c]) {
				visited[r][c] = 1;
				cnt++;
				if (r + 1 < n && arr[r + 1][c] <= d && !visited[r + 1][c]) {
					q.push({ r + 1, c });
				}
				if (r - 1 >= 0 && arr[r - 1][c] <= d && !visited[r - 1][c]) {
					q.push({ r - 1, c });
				}
				if (c + 1 < m && arr[r][c + 1] <= d && !visited[r][c + 1]) {
					q.push({ r, c + 1 });
				}
				if (c - 1 >= 0 && arr[r][c - 1] <= d && !visited[r][c - 1]) {
					q.push({ r, c - 1 });
				}
			}
		}
	}
	return cnt;
}

void solve() {
	int left = 1, right = 1000000;
	while (left <= right) {
		init();
		int mid = (left + right) / 2;
		int res = bfs(mid);
		if (res >= k) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}