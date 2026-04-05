#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9

/*
	1024 * 120 * 각 케이스마다 bfs 네 번

*/

typedef long long ll;
//h, r, c
typedef pair<int, pair<int, int>> ppp;

int arr[5][5][5];
int cpy[5][5][5];
int visited[5][5][5];

int dr[6] = { -1, 0, 1, 0, 0, 0 };
int dc[6] = { 0, 1, 0, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int ans = INF;

void clear() {
	for (int h = 0; h < 5; ++h) {
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				visited[h][r][c] = 0;
			}
		}
	}
}

int checkRange(int h, int r, int c) {
	if (h >= 0 && h < 5 && r >= 0 && r < 5 && c >= 0 && c < 5) {
		return true;
	}
	return false;
}

void bfs(int sr, int sc, int er, int ec) {
	if (!cpy[0][sr][sc] || !cpy[4][er][ec] || ans == 12) {
		return;
	}
	clear();

	queue<ppp> q;

	q.push({ 0, {sr, sc} });
	visited[0][sr][sc] = 1;

	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		if (time > ans) {
			return;
		}

		while (size--) {
			ppp front = q.front();
			q.pop();

			int h = front.first;
			int r = front.second.first;
			int c = front.second.second;
			if (h == 4 && r == er && c == ec) {
				ans = min(ans, time);
				return;
			}

			for (int i = 0; i < 6; ++i) {
				int nh = h + dh[i];
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (checkRange(nh, nr, nc) && !visited[nh][nr][nc] && cpy[nh][nr][nc]) {
					visited[nh][nr][nc] = 1;
					q.push({ nh, {nr, nc} });
				}
			}
		}
		time++;
	}
}

void rotate(int h) {
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			cpy[h][r][c] = arr[h][4 - c][r];
		}
	}
	for (int r = 0; r < 5; ++r) {
		for (int c = 0; c < 5; ++c) {
			arr[h][r][c] = cpy[h][r][c];
		}
	}

}

int cnt;

void brute_force(int depth, int bitmask) {
	if (bitmask == 31 || ans == 12) {
		bfs(0, 0, 4, 4);
		return;
	}
	for (int i = 0; i < 5; ++i) {
		if (((bitmask >> i) & 1) == 0) {
			for (int r = 0; r < 5; ++r) {
				for (int c = 0; c < 5; ++c) {
					cpy[depth][r][c] = arr[i][r][c];
				}
			}
			brute_force(depth + 1, bitmask | (1 << i));
		}
	}
}

void dfs(int depth) {
	if (ans == 12) {
		return;
	}
	if (depth != 5) {
		for (int i = 0; i < 4; ++i) {
			rotate(depth);
			dfs(depth + 1);
		}
	}
	else {
		brute_force(0, 0);
	}
}

void solve() {

	dfs(0);

	if (ans == INF) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; ++i) {
		for (int r = 0; r < 5; ++r) {
			for (int c = 0; c < 5; ++c) {
				cin >> arr[i][r][c];
			}
		}
	}
	solve();
	cout << ans;

}
