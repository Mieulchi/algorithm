#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[1001][1001];
int visited[1001][1001];
int ans;

void solve() {
	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push({ { 1, 1 }, {k, 1} });

	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> front = q.front();
		q.pop();
		pair<int, int> coor = front.first;
		int r = coor.first;
		int c = coor.second;
		int power = front.second.first;
		int time = front.second.second;
		if (r == n && c == m) {
			if (!ans || time < ans) {
				ans = time;
			}
		}
		if (visited[r][c]) {
			if (power + 1 <= visited[r][c]) {
				continue;
			}
		}
		visited[r][c] = power + 1;

		if (r + 1 <= n) {
			if (arr[r + 1][c] == 0) {
				if (!visited[r + 1][c] || visited[r + 1][c] < power + 1) {
					q.push({ {r + 1, c}, {power, time + 1} });
				}
			}
			else {
				if (power) {
					if (!visited[r + 1][c] || visited[r + 1][c] < power) {
						q.push({ { r + 1, c }, {power - 1, time + 1} });
					}
				}
			}
		}
		if (r - 1 >= 1) {
			if (arr[r - 1][c] == 0) {
				if (!visited[r - 1][c] || visited[r - 1][c] < power + 1) {
					q.push({ {r - 1, c}, { power, time + 1} });
				}
			}
			else {
				if (power) {
					if (!visited[r - 1][c] || visited[r - 1][c] < power) {
						q.push({ { r - 1, c }, { power - 1, time + 1} });
					}
				}
			}
		}
		if (c + 1 <= m) {
			if (arr[r][c + 1] == 0) {
				if (!visited[r][c + 1] || visited[r][c + 1] < power + 1) {
					q.push({ {r, c + 1}, { power, time + 1} });
				}
			}
			else {
				if (power) {
					if (!visited[r][c + 1] || visited[r][c + 1] < power) {
						q.push({ { r, c + 1 }, { power - 1, time + 1} });
					}
				}
			}
		}
		if (c - 1 >= 1) {
			if (arr[r][c - 1] == 0) {
				if (!visited[r][c - 1] || visited[r][c - 1] < power + 1) {
					q.push({ {r, c - 1}, { power, time + 1} });
				}
			}
			else {
				if (power) {
					if (!visited[r][c - 1] || visited[r][c - 1] < power) {
						q.push({ { r, c - 1 }, { power - 1, time + 1} });
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