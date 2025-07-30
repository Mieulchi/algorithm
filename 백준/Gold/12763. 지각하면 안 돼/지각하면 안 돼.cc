#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> p;

int n, t, m, l;

int cost[101][10001];
pair<int, int> best[101];
vector<p> v[101];

int ans;

struct cmp {
	bool operator() (p p1, p p2) {
		if (p1.second.first == p2.second.first) {
			return p1.second.second > p2.second.second;
		}
		return p1.second.first > p2.second.first;
	}
};

priority_queue<p, vector<p>, cmp> pq;

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10001; j++) {
			cost[i][j] = 1110000;
		}
	}
	cost[1][0] = 0;
	for (int i = 0; i < v[1].size(); i++) {
		pq.push(v[1][i]);
	}

	while (!pq.empty()) {
		p top = pq.top();
		pq.pop();

		int now = top.first;
		int flag = 1;
		int nowT = top.second.first;
		int nowC = top.second.second;

		if (cost[now][nowC] < nowT) {
			continue;
		}

		cost[now][nowC] = nowT;

		if (now == n) {
			continue;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int time = v[now][i].second.first;
			int price = v[now][i].second.second;

			if (next == 1) {
				continue;
			}

			int nextT = nowT + time;
			int nextC = nowC + price;

			if (nextC > m || nextT > t) {
				continue;
			}

			if (cost[next][nextC] > nextT) {
				cost[next][nextC] = nextT;
				pq.push({ next,{ nextT, nextC } });
			}

		}
	}
	for (int i = 0; i <= m; i++) {
		if (cost[n][i] <= t) {
			ans = i;
			return;
		}
	}
	ans = -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> t >> m >> l;
	int a, b, c, d;
	while (l--) {
		cin >> a >> b >> c >> d;
		v[a].push_back({ b,{c,d} });
		v[b].push_back({ a,{c,d} });
	}
	solve();
	cout << ans;
}