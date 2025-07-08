#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int N, T, R, C;
char arr[501][501];
int dist[501][501][2];
vector<int> vr[501];
vector<int> vc[501];
int ans;

//{r,c}, {time, mode}
typedef pair<pair<int, int>, pair<int, int>> pp;

struct cmp {
	bool operator()(pp pp1, pp pp2) {
		return pp1.second.first > pp2.second.first;
	}
};

priority_queue<pp, vector<pp>, cmp> pq;

void solve() {
	pq.push({ { 1, 1 }, { 0, 0 } });
	pq.push({ { 1, 1 }, { T, 1 } });
	while (!pq.empty()) {
		pp front = pq.top();
		pq.pop();

		int r = front.first.first;
		int c = front.first.second;
		int time = front.second.first;
		int mode = front.second.second;

		if (time > dist[r][c][mode]) {
			continue;
		}

		if (r == R && c == C) {
			if (!ans || time < ans) {
				ans = time;
			}
			break;
		}

		pair<int, int> info = { time + 1, 0 };
		if (r + 1 <= N && (dist[r + 1][c][0] > time + 1)) {
			dist[r + 1][c][0] = time + 1;
			pq.push({ {r + 1, c}, info });
		}
		if (r - 1 > 0 && (dist[r - 1][c][0] > time + 1)) {
			dist[r - 1][c][0] = time + 1;
			pq.push({ {r - 1, c}, info });
		}
		if (c + 1 <= N && (dist[r][c + 1][0] > time + 1)) {
			dist[r][c + 1][0] = time + 1;
			pq.push({ {r, c + 1}, info });
		}
		if (c - 1 > 0 && (dist[r][c - 1][0] > time + 1)) {
			dist[r][c - 1][0] = time + 1;
			pq.push({ {r, c - 1}, info });
		}

		int ntime = time + 1 + (mode ? 0 : T);
		info = { ntime , 1 };
		if (vr[r].size()) {
			int right = 0, left = 0;
			for (int i = 0; i < vr[r].size(); i++) {
				if (vr[r][i] > c) {
					right = vr[r][i];
					break;
				}
				if (vr[r][i] < c) {
					left = vr[r][i];
				}
			}
			if (right) {
				if (dist[r][right][1] > ntime) {
					dist[r][right][1] = ntime;
					pq.push({ {r, right}, info });
				}
			}
			if (left) {
				if (dist[r][left][1] > ntime) {
					dist[r][left][1] = ntime;
					pq.push({ {r, left}, info });
				}
			}
		}

		if (vc[c].size()) {
			int right = 0, left = 0;
			for (int i = 0; i < vc[c].size(); i++) {
				if (vc[c][i] > r) {
					right = vc[c][i];
					break;
				}
				if (vc[c][i] < r) {
					left = vc[c][i];
				}
			}
			if (right) {
				if (dist[right][c][1] > ntime) {
					dist[right][c][1] = ntime;
					pq.push({ {right, c}, info });
				}
			}
			if (left) {
				if (dist[left][c][1] > ntime) {
					dist[left][c][1] = ntime;
					pq.push({ {left, c}, info });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T >> R >> C;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j][0] = dist[i][j][1] = INF;
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				vr[i].push_back({ j });
				vc[j].push_back({ i });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(vr[i].begin(), vr[i].end());
		sort(vc[i].begin(), vc[i].end());
	}
	dist[1][1][0] = 0;
	dist[1][1][1] = T;
	solve();
	cout << ans;
}