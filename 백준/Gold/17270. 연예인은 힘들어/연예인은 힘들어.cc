#include <iostream>
#include <queue>
using namespace std;

int v, m;
vector<pair<int, int>> V[101];
int dist[2][101];
int J, S;
int ans;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void dijkstra() {
	for (int i = 0; i < 2; i++) {
		int now = i ? S : J;
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();

		for (int i = 0; i < V[now].size(); i++) {
			pq.push({ V[now][i].first, V[now][i].second });
		}

		while (!pq.empty()) {
			pair<int, int> front = pq.top();
			pq.pop();
			int n = front.first;
			if ((!dist[i][n] || dist[i][n] > front.second) && n != now){
				dist[i][n] = front.second;
				for (int j = 0; j < V[n].size(); j++) {
					int next = V[n][j].first;
					if (!dist[i][next] || dist[i][next] > dist[i][n] + V[n][j].second) {
						pq.push({ next, dist[i][n] + V[n][j].second });
					}
				}
			}
		}
	}
}

void solve() {
	dijkstra();

	int min = 0;
	for (int i = 1; i <= v; i++) {
		if ((dist[0][i] && dist[1][i]) && (!min || min >= dist[0][i] + dist[1][i])) {
			min = dist[0][i] + dist[1][i];
		}
	}
	int c = 0;
	for (int i = 1; i <= v; i++) {
		if (i != S && i != J) {
			if ((dist[0][i] && dist[1][i]) && min == dist[0][i] + dist[1][i]) {
				if (dist[0][i] <= dist[1][i]) {
					if (!c || c >= dist[0][i]) {
						if (c == dist[0][i]) {
							if (!ans || i < ans) {
								ans = i;
							}
						}
						else {
							c = dist[0][i];
							ans = i;
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

	cin >> v >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	cin >> J >> S;

	solve();

	cout << ans;
}