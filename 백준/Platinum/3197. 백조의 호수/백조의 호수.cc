#include <iostream>
#include <queue>
using namespace std;

int R, C;
char arr[1500][1500];
int visited[1500][1500];
queue<pair<int, int>> nxt;
queue<pair<int, int>> q[2];
int r1, r2, c1, c2;
int ans;

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 'X') {
				nxt.push({ i,j });
			}
		}
	}
}

bool f() {
	for (int i = 0; i < 2; i++) {
		queue<pair<int, int>> tmp;
		while (!q[i].empty()) {
			pair<int, int> front = q[i].front();
			q[i].pop();
			int r = front.first;
			int c = front.second;
			if (visited[r][c] && arr[r][c] == (i ? 'L' : 'l')) {
				continue;
			}
			visited[r][c] = 1;
			arr[r][c] = i ? 'L' : 'l';
			if (r + 1 < R) {
				if (arr[r + 1][c] == '.') {
					q[i].push({r + 1, c});
				}
				else {
					if (arr[r + 1][c] != arr[r][c]) {
						if (arr[r + 1][c] == 'X') {
							tmp.push({ r + 1, c });
						}
						else {
							return 1;
						}
					}
				}
			}
			if (r - 1 >= 0) {
				if (arr[r - 1][c] == '.') {
					q[i].push({r - 1, c});
				}
				else {
					if (arr[r - 1][c] != arr[r][c]) {
						if (arr[r - 1][c] == 'X') {
							tmp.push({ r - 1, c });
						}
						else {
							return 1;
						}
					}
				}
			}
			if (c + 1 < C) {
				if (arr[r][c + 1] == '.') {
					q[i].push({r, c + 1});
				}
				else {
					if (arr[r][c + 1] != arr[r][c]) {
						if (arr[r][c + 1] == 'X') {
							tmp.push({ r, c + 1 });
						}
						else {
							return 1;
						}
					}
				}
			}
			if (c - 1 >= 0) {
				if (arr[r][c - 1] == '.') {
					q[i].push({r, c - 1});
				}
				else {
					if (arr[r][c - 1] != arr[r][c]) {
						if (arr[r][c - 1] == 'X') {
							tmp.push({ r, c - 1 });
						}
						else {
							return 1;
						}
					}
				}
			}
		}
		q[i] = tmp;
	}
	return 0;
}

void melt() {
	int size = nxt.size();
	while (size--) {
		pair<int, int> front = nxt.front();
		nxt.pop();
		int r = front.first;
		int c = front.second;
		visited[r][c] = 1;
		if (r + 1 < R) {
			if (arr[r + 1][c] == 'X') {
				nxt.push({ r + 1, c });
				arr[r + 1][c] = arr[r][c];
			}
		}
		if (r - 1 >= 0) {
			if (arr[r - 1][c] == 'X') {
				nxt.push({ r - 1, c });
				arr[r - 1][c] = arr[r][c];
			}
		}
		if (c + 1 < C) {
			if (arr[r][c + 1] == 'X') {
				nxt.push({ r, c + 1 });
				arr[r][c + 1] = arr[r][c];
			}
		}
		if (c - 1 >= 0) {
			if (arr[r][c - 1] == 'X') {
				nxt.push({ r, c - 1 });
				arr[r][c - 1] = arr[r][c];
			}
		}
	}
}

void solve() {
	init();
	while (true) {
		if (f()) {
			break;
		}
		melt();
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') {
				if (q[0].empty()) {
					q[0].push({ i, j });
				}
				else {
					q[1].push({ i, j });
				}
			}
		}
	}
	solve();
	cout << ans;
} 