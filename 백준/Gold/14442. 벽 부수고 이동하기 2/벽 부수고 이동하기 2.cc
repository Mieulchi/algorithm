#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[1001][1001];
int visited[1001][1001];
int ans;

void solve() {
	queue<pair<pair<int, int>, int>> q;

	q.push({ { 1, 1 }, k });

	int time = 1;
	while (!q.empty()) {
		queue<pair<pair<int, int>, int>> tmp;
		int flag = 0;
		while (!q.empty()) {
			pair<pair<int, int>, int> front = q.front();
			q.pop();
			pair<int, int> coor = front.first;
			int r = coor.first;
			int c = coor.second;
			if (r == n && c == m) {
				flag = 1;
				break;
			}
			int power = front.second;
			if (visited[r][c]) {
				if (power + 1 <= visited[r][c]) {
					continue;
				}
			}
			
			visited[r][c] = power + 1;

			if (r + 1 <= n) {
				if (arr[r + 1][c] == 0) {
					if (!visited[r + 1][c] || visited[r + 1][c] < power + 1) {
						tmp.push({ {r + 1, c}, power });
					}
				}
				else {
					if (power) {
						if (!visited[r + 1][c] || visited[r + 1][c] < power) {
							tmp.push({ { r + 1, c }, power - 1 });
						}
					}
				}
			}
			if (r - 1 >= 1) {
				if (arr[r - 1][c] == 0) {
					if (!visited[r - 1][c] || visited[r - 1][c] < power + 1) {
						tmp.push({ {r - 1, c}, power });
					}
				}
				else {
					if (power) {
						if (!visited[r - 1][c] || visited[r - 1][c] < power) {
							tmp.push({ { r - 1, c }, power - 1 });
						}
					}
				}
			}
			if (c + 1 <= m) {
				if (arr[r][c + 1] == 0) {
					if (!visited[r][c + 1] || visited[r][c + 1] < power + 1) {
						tmp.push({ {r, c + 1}, power });
					}
				}
				else {
					if (power) {
						if (!visited[r][c + 1] || visited[r][c + 1] < power) {
							tmp.push({ { r, c + 1 }, power - 1 });
						}
					}
				}
			}
			if (c - 1 >= 1) {
				if (arr[r][c - 1] == 0) {
					if (!visited[r][c - 1] || visited[r][c - 1] < power + 1) {
						tmp.push({ {r, c - 1}, power });
					}
				}
				else {
					if (power) {
						if (!visited[r][c - 1] || visited[r][c - 1] < power) {
							tmp.push({ { r, c - 1 }, power - 1 });
						}
					}
				}
			}
		}
		if (flag) {
			ans = time;
			break;
		}
		q = tmp;
		time++;
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