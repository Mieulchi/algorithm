#include <iostream>
#include <queue>
using namespace std;

int n, m, c;
int sr, sc;
int arr[1001][1001];
int visited[1001][1001];
int ans;

void solve() {
	queue<pair<int, int>> q;
	q.push({ sr, sc });
	int pal = c;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> front = q.front();
			q.pop();
			int r = front.first;
			int c = front.second;
			if (visited[r][c]) {
				continue;
			}
			visited[r][c] = 1;
			pal += arr[r][c];
			if (r + 1 <= n && !visited[r + 1][c] && arr[r + 1][c] != -1) {
				q.push({ r + 1, c });
			}
			if (r - 1 > 0 && !visited[r - 1][c] && arr[r - 1][c] != -1) {
				q.push({ r - 1, c });
			}
			if (c + 1 <= m && !visited[r][c + 1] && arr[r][c + 1] != -1) {
				q.push({ r, c + 1 });
			}
			if (c - 1 > 0 && !visited[r][c - 1] && arr[r][c - 1] != -1) {
				q.push({ r, c - 1 });
			}
		}
		pal -= c;
		if (pal > ans) {
			ans = pal;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> c;
	cin >> sr >> sc;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}