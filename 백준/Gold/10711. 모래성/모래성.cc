#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
char arr[1000][1000];
int visited[1000][1000];
int ans;

int checkRange(int r, int c) {
	if (r < n && r >= 0 && c < m && c >= 0) {
		return 1;
	}
	return 0;
}

//return 1 if collapse
int checkCollapse(int r, int c) {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		if (checkRange(r + dr[i], c + dc[i]) && arr[r + dr[i]][c + dc[i]] == '.') {
			++cnt;
		}
	}
	if (arr[r][c] != '.' && arr[r][c] - '0' <= cnt) {
		return true;
	}
	return false;
}

void solve() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (checkCollapse(i, j)) {
				q.push({ i, j });
			}
		}
	}
	while (!q.empty()) {
		++ans;
		int size = q.size();
		queue<pair<int, int>> tmp;
		while (size--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (!visited[r][c]) {
				visited[r][c] = 1;
				arr[r][c] = '.';
				for (int i = 0; i < 8; ++i) {
					if (checkRange(r + dr[i], c + dc[i])) {
						tmp.push({ r + dr[i], c + dc[i] });
					}
				}
			}
		}

		size = tmp.size();
		while (size--) {
			int r = tmp.front().first;
			int c = tmp.front().second;
			tmp.pop();
			if (checkCollapse(r, c)) {
				q.push({ r, c });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			arr[i][j] = s[j];
		}
	}
	solve();
	cout << ans;
}