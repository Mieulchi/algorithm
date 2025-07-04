#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[100][100];
int visited[100][100];
queue<pair<int, int>> q[10000];
int ans;

void bfs(int pr, int pc, int num) {
	queue<pair<int, int>> tq;
	tq.push({ pr, pc });
	while (!tq.empty()) {
		pair<int, int> front = tq.front();
		tq.pop();
		int r = front.first;
		int c = front.second;
		arr[r][c] = num;
		if (visited[r][c]) {
			continue;
		}
		visited[r][c] = 1;
		q[num].push({ r, c });

		if (r + 1 < n && arr[r + 1][c] && !visited[r + 1][c]) {
			tq.push({ r + 1, c });
		}
		if (r - 1 < n && arr[r - 1][c] && !visited[r - 1][c]) {
			tq.push({ r - 1, c });
		}
		if (c + 1 < n && arr[r][c + 1] && !visited[r][c + 1]) {
			tq.push({ r, c + 1 });
		}
		if (c - 1 < n && arr[r][c - 1] && !visited[r][c - 1]) {
			tq.push({ r, c - 1 });
		}
	}
}

int search(int idx) {
	int tvisited[100][100] = { 0 };
	int cnt = 0;
	queue<pair<int, int>> tq = q[idx];

	while (true) {
		int size = tq.size();
		while (size--) {
			pair<int, int> front = tq.front();
			tq.pop();
			int r = front.first;
			int c = front.second;
			if (tvisited[r][c]) {
				continue;
			}
			tvisited[r][c] = 1;

			if (r + 1 < n && !tvisited[r + 1][c]) {
				if (!arr[r + 1][c]) {
					tq.push({ r + 1, c });
				}
				else {
					if (arr[r + 1][c] != idx) {
						return cnt;
					}
				}
			}
			if (r - 1 >= 0 && !tvisited[r - 1][c]) {
				if (!arr[r - 1][c]) {
					tq.push({ r - 1, c });
				}
				else {
					if (arr[r - 1][c] != idx) {
						return cnt;
					}
				}
			}
			if (c + 1 < n && !tvisited[r][c + 1]) {
				if (!arr[r][c + 1]) {
					tq.push({ r, c + 1 });
				}
				else {
					if (arr[r][c + 1] != idx) {
						return cnt;
					}
				}
			}
			if (c - 1 >= 0 && !tvisited[r][c - 1]) {
				if (!arr[r][c - 1]) {
					tq.push({ r, c - 1 });
				}
				else {
					if (arr[r][c - 1] != idx) {
						return cnt;
					}
				}
			}
		}
		cnt++;
	}
}

void solve() {
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visited[i][j]) {
				bfs(i, j , num++);
			}
		}
	}
	
	for (int i = 1; i < num; i++) {
		int res = search(i);
		if (!ans || res < ans) {
			ans = res;
		}
		if (ans == 1) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << ans;
}