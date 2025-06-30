#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[1001][1001];
int visited[1001][1001][11][2];
int ans;

void solve() {
	queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
	q.push({{ { 1, 1 }, { k, 1 } }, 1});

	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> front = q.front().first;
		int r = front.first.first;
		int c = front.first.second;
		int power = front.second.first;
		int day = front.second.second;
		int time = q.front().second;
		q.pop();

		if (r == n && c == m) {
			if (!ans || time < ans) {
				ans = time;
			}
		}

		if (!visited[r][c][power][day] || time < visited[r][c][power][day] ) {
			visited[r][c][power][day] = time;
		}
		else {
			continue;
		}

		int next = day ? 0 : 1;

		if (r + 1 <= n) {
			if (arr[r + 1][c] == 0) {
				if (!visited[r + 1][c][power][next] || visited[r + 1][c][power][next] > time + 1) {
					q.push({ {{r + 1, c}, {power, next}}, time + 1 });
				}
			}
			else {
				if (power) {
					if (day) {
						if (!visited[r + 1][c][power - 1][next] || visited[r + 1][c][power - 1][next] > time + 1) {
							q.push({ {{r + 1, c}, {power - 1, next}}, time + 1 });
						}
					}
					else {
						if (!visited[r + 1][c][power - 1][day] || visited[r + 1][c][power - 1][day] > time + 2) {
							q.push({ {{r + 1, c}, {power - 1, day}}, time + 2 });
						}
					}
				}
			}
		}
		if (r - 1 >= 1) {
			if (arr[r - 1][c] == 0) {
				if (!visited[r - 1][c][power][next] || visited[r - 1][c][power][next] > time + 1) {
					q.push({ { {r - 1, c}, {power, next} }, time + 1 });
				}
			}
			else {
				if (power) {
					if (day) {
						if (!visited[r - 1][c][power - 1][next] || visited[r - 1][c][power - 1][next] > time + 1) {
							q.push({ { {r - 1, c}, {power - 1, next} }, time + 1 });
						}
					}
					else {
						if (!visited[r - 1][c][power - 1][day] || visited[r - 1][c][power - 1][day] > time + 2) {
							q.push({ { {r - 1, c}, {power - 1, day} }, time + 2 });
						}
					}
				}
			}
		}
		if (c + 1 <= m) {
			if (arr[r][c + 1] == 0) {
				if (!visited[r][c + 1][power][next] || visited[r][c + 1][power][next] > time + 1) {
					q.push({ {{r , c + 1}, {power, next}}, time + 1 });
				}
			}
			else {
				if (power) {
					if (day) {
						if (!visited[r][c + 1][power - 1][next] || visited[r][c + 1][power - 1][next] > time + 1) {
							q.push({ {{r , c + 1}, {power - 1, next}}, time + 1 });

						}
					}
					else {
						if (!visited[r][c + 1][power - 1][day] || visited[r][c + 1][power - 1][day] > time + 2) {
							q.push({ {{r , c + 1}, {power - 1, day}}, time + 2 });
						}
					}
				}
			}
		}
		if (c - 1 >= 1) {
			if (arr[r][c - 1] == 0) {
				if (!visited[r][c - 1][power][next] || visited[r][c - 1][power][next] > time + 1) {
					q.push({ {{r , c - 1}, {power, next }}, time + 1 });
				}
			}
			else {
				if (power) {
					if (day) {
						if (!visited[r][c - 1][power - 1][next] || visited[r][c - 1][power - 1][next] > time + 1) {
							q.push({ {{r , c - 1}, {power - 1, next }}, time + 1 });

						}
					}
					else {
						if (!visited[r][c - 1][power - 1][day] || visited[r][c - 1][power - 1][day] > time + 2) {
							q.push({ {{r , c - 1}, {power - 1, day }}, time + 2 });
						}
					}
				}
			}
		}
	}
	if (!ans) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	if (n != 1 || m != 1) {
		solve();
	}
	else {
		ans = 1;
	}
	cout << ans;
}