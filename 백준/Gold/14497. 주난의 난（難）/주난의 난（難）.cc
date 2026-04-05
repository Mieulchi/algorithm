#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

#define INF 1e9

typedef long long ll;
typedef pair<int, int> pp;

int n, m;
int r1, c1, r2, c2;
char map[300][300];
int visited[300][300];
int ans = INF;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void solve() {
	deque<pp> dq;
	dq.push_back({ r1, c1 });
	visited[r1][c1] = 0;

	while (!dq.empty()) {

		pp front = dq.front();
		dq.pop_front();

		int r = front.first;
		int c = front.second;
		int time = visited[r][c];
		if (time >= ans) {
			continue;
		}

		if (r == r2 && c == c2) {
			ans = min(ans, time);
			break;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr >= 0 && nr < n && nc >= 0 && nc < m && time < ans) {
				if (map[nr][nc] == '0') {
					if (time < visited[nr][nc]) {
						visited[nr][nc] = time;
						dq.push_front({ nr, nc });
					}
				}
				else {
					if (time + 1 < visited[nr][nc]) {
						visited[nr][nc] = time + 1;
						dq.push_back({ nr, nc });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> r1 >> c1 >> r2 >> c2;
	r1--;
	c1--;
	r2--;
	c2--;

	string s;
	for (int r = 0; r < n; ++r) {
		cin >> s;
		for (int c = 0; c < m; ++c) {
			map[r][c] = s[c];
			visited[r][c] = INF;
		}
	}

	solve();

	cout << ans;

}
