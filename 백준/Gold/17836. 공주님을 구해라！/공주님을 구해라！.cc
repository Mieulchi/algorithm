#include <iostream>
#include <queue>
using namespace std;

int n, m, t;
int mat[101][101];
int visited[101][101];
int ans;

queue<pair<pair<int, int>, int>> q;
queue<pair<pair<int, int>, int>> tmp;
int cnt;

void mypush(int r, int c, int gram) {
	if (r == n && c == m) {
		if ((!ans || cnt < ans) && cnt <= t) {
			ans = cnt;
		}
		return;
	}
	if (r <= n && c <= m && r >= 1 && c >= 1 && !visited[r][c] || cnt < visited[r][c]) {
		if (mat[r][c] == 0) {
			tmp.push({ {r , c}, gram });
			visited[r][c] = cnt;
		}
		else if (mat[r][c] == 1) {
			if (gram) {
				tmp.push({ {r , c}, 1 });
				visited[r][c] = cnt;
			}
		}
		else {
			if ((!ans || cnt + (n - r + m - c) < ans) && cnt + (n - r + m - c) <= t) {
				ans = cnt + (n - r + m - c);
			}
			visited[r][c] = cnt;
		}
	}
}

void solve() {
	q.push({ {1, 1}, 0 });
	visited[1][1] = 1;
	while (!q.empty()) {
		tmp = {};
		cnt++;
		while (!q.empty()) {
			pair<pair<int, int>, int> front = q.front();
			q.pop();
			int r = front.first.first;
			int c = front.first.second;
			int gram = front.second;
			mypush(r + 1, c, gram);
			mypush(r - 1, c, gram);
			mypush(r, c + 1, gram);
			mypush(r, c - 1, gram);
		}
		q = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	solve();
	if (!ans) {
		cout << "Fail";
	}
	else {
		cout << ans;
	}
}