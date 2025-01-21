#include <iostream>
#include <queue>
using namespace std;

int n, m;
int sr, sc;
char classRoom[50][50];
int visited[50][50][5];

int t;
int ans;
int dir;
int flag;

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visited[i][j][1] = 0;
			visited[i][j][2] = 0;
			visited[i][j][3] = 0;
			visited[i][j][4] = 0;
		}
	}
}

vector<pair<pair<int, int>, pair<int, int>>> v;

void bfs(int r, int c) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {r, c}, {dir, 0} });
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> p = q.front();
		q.pop();
		int time = p.second.second + 1;

		r = p.first.first;
		c = p.first.second;
		dir = p.second.first;

		if (visited[r][c][dir]) {
			continue;
		}
		visited[r][c][dir] = 1;

		if (classRoom[r][c] == 'C' && (!t || p.second.second <= t)) {
			if (!flag && p.second.second < t) {
				v.clear();
			}
			t = p.second.second;
			if (!flag) {
				pair<pair<int, int>, pair<int, int>> tmp = { {r, c}, {dir, p.second.second} };
				v.push_back(tmp);
			}
		}

		if (!visited[r + 1][c][3] && r + 1 < n && p.second.first != 3 && classRoom[r + 1][c] != '#') {
			q.push({ { r + 1, c }, {3, time} });
		}
		if (!visited[r - 1][c][1] && r - 1 >= 0 && p.second.first != 1 && classRoom[r - 1][c] != '#') {
			q.push({ { r - 1, c }, {1, time} });
		}
		if (!visited[r][c + 1][2] && c + 1 < m && p.second.first != 2 && classRoom[r][c + 1] != '#') {
			q.push({ { r, c + 1 }, {2, time} });
		}
		if (!visited[r][c - 1][4] && c - 1 >= 0 && p.second.first != 4 && classRoom[r][c - 1] != '#') {
			q.push({ { r, c - 1 }, {4, time} });
		}
	}
}

void solve() {
	bfs(sr, sc);
	if (v.empty()) {
		ans = -1;
		return;
	}

	ans += t;
	flag = 1;
	int tmp = 0;

	for (int i = 0; i < v.size(); i++) {
		t = 0;
		init();
		classRoom[v[i].first.first][v[i].first.second] = '.';

		dir = v[i].second.first;
		bfs(v[i].first.first, v[i].first.second);
		if (t && (!tmp || t < tmp)) {
			tmp = t;
		}

		classRoom[v[i].first.first][v[i].first.second] = 'C';
	}

	if (!tmp) {
		ans = -1;
	}
	else {
		ans += tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> classRoom[i][j];
			if (classRoom[i][j] == 'S') {
				sr = i;
				sc = j;
			}
		}
	}

	solve();

	cout << ans;
}