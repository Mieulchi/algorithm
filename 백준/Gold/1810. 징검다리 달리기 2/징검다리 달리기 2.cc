#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 1000000007
#define pp pair<pair<int, int>, double> 

int n, f;

map<pair<int, int>, int> m;

int dist[50001];

double ans = INF;

struct cmp {
	bool operator()(pp a, pp b) {
		return a.second > b.second;
	}
};


void solve() {
	for (int i = 0; i <= n; ++i) {
		dist[i] = INF;
	}

	priority_queue<pp, vector<pp>, cmp> pq;
	pq.push({ { 0,0 }, 0.0 });

	while (!pq.empty()) {
		pp front = pq.top();
		int x = front.first.first;
		int y = front.first.second;
		double d = front.second;

		pq.pop();

		int node = m[{x, y}];

		if (dist[node] > d) {
			dist[node] = d;

			if (y == f) {
				ans = min(ans, d);
			}

			for (int i = -2; i < 3; ++i) {
				for (int j = -2; j < 3; ++j) {
					int nextx = x + i;
					int nexty = y + j;
					if (m.count({ nextx, nexty })) {
						int v = m[{nextx, nexty}];
						double nextDist = sqrt(i * i + j * j);
						if (v != node && (dist[v] > d + nextDist)) {
							pq.push({ { nextx, nexty }, d + nextDist });
						}
					}
				}
			}

		}
	}
	if (ans == INF) {
		ans = -1;
	}
	else {
		ans = round(ans);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> f;

	int a, b;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		m[{a, b}] = i;
	}
	if (f) {
		solve();
	}
	cout << ans;
}