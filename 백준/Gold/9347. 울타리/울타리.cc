#include <iostream>
#include <queue>
using namespace std;

int R, C;
int arr[1000][1000];
int visited[1000][1000];
int ans, cnt;
queue<pair<int, int>> q;

void init() {
	for (int i = 0; i < R; i++) { for (int j = 0; j < C; j++) { visited[i][j] = 0; } }
}

int bfs(int pr, int pc) {
	queue<pair<int, int>> tmp;
	tmp.push({ pr, pc });
	int ret = 0;
	while (!tmp.empty()) {
		pair<int, int> front = tmp.front();
		tmp.pop();
		int r = front.first;
		int c = front.second;
		if (!visited[r][c]) {
			visited[r][c] = 1;
			ret++;
			if (r + 1 < R) {
				if (!arr[r + 1][c]) {
					tmp.push({ r + 1, c });
				}
				else {
					q.push({ r + 1, c });
				}
			}
			if (r - 1 >= 0) {
				if (!arr[r - 1][c]) {
					tmp.push({ r - 1, c });
				}
				else {
					q.push({ r - 1, c });
				}
			}
			if (c + 1 < C) {
				if (!arr[r][c + 1]) {
					tmp.push({ r, c + 1 });
				}
				else {
					q.push({ r, c + 1 });
				}
			}
			if (c - 1 >= 0) {
				if (!arr[r][c - 1]) {
					tmp.push({ r, c - 1 });
				}
				else {
					q.push({ r, c - 1 });
				}
			}
		}	
	}
	return ret;
}


void f() {
	for (int i = 0; i < C; i++) {
		if (!arr[0][i]) {
			cnt += bfs(0, i);
		}
		else {
			q.push({ 0, i });
		}
		if (!arr[R - 1][i]) {
			cnt += bfs(R - 1, i);
		}
		else {
			q.push({ R - 1, i });
		}
	}
	for (int i = 0; i < R; i++) {
		if (!arr[i][0]) {
			cnt += bfs(i, 0);
		}
		else {
			q.push({ i, 0 });
		}
		if (!arr[i][C - 1]) {
			cnt += bfs(i, C - 1);
		}
		else {
			q.push({ i, C - 1 });
		}
	}
}

void solve() {
	q = queue<pair<int, int>>();
	init();
	cnt = 0;
	ans = 0;
	f();

	int security = 0;
	while (!q.empty()) {
		int size = q.size();
		security++;
		int t = 0;
		while (size--) {
			pair<int, int> front = q.front();
			q.pop();
			int r = front.first;
			int c = front.second;
			if (!visited[r][c]) {
				visited[r][c] = 1;
				if (r + 1 < R && !visited[r + 1][c]) {
					if (!arr[r + 1][c]) {
						t += bfs(r + 1, c);
					}
					else {
						q.push({ r + 1, c });
					}
				}
				if (r - 1 >= 0 && !visited[r - 1][c]) {
					if (!arr[r - 1][c]) {
						t += bfs(r - 1, c);
					}
					else {
						q.push({ r - 1, c });
					}
				}
				if (c + 1 < C && !visited[r][c + 1]) {
					if (!arr[r][c + 1]) {
						t += bfs(r, c + 1);
					}
					else {
						q.push({ r, c + 1 });
					}
				}
				if (c - 1 >= 0 && !visited[r][c - 1]) {
					if (!arr[r][c - 1]) {
						t += bfs(r, c - 1);
					}
					else {
						q.push({ r, c - 1 });
					}
				}
			}
		}
		if (t) {
			ans = security;
			cnt = t;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
		cout << ans << ' ' << cnt << '\n';
	}
}