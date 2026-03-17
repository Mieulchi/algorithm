#include <iostream>
#include <queue>
using namespace std;

#define INF 1000000007
typedef long long ll;
typedef pair<int, pair<ll, int>> ppp;

int n, m, a, b, ans = INF;
ll c;

vector<ppp> v[100001];
ll dist[100001];
ll minDist[100001];

struct cmp {
	bool operator()(ppp p1, ppp p2) {
		return p1.second.first > p2.second.first;
	}
};

void solve() {
	for (int i = 1; i <= n; ++i) {
		minDist[i] = dist[i] = INF;
	}

	priority_queue<ppp, vector<ppp>, cmp> pq;

	pq.push({ a, { 0, 0 } });

	while (!pq.empty()) {
		ppp front = pq.top();
		pq.pop();
		int now = front.first;
		ll w = front.second.first;
		int shame = front.second.second;

		if (now == b && w && w <= c) {
			ans = min(ans, shame);
		}

		if (dist[now] < w || w > c) {
			continue;
		}


		dist[now] = w;
		
		for (ppp p : v[now]) {
			int next = p.first;
			ll nW = p.second.first;
			int nShame = p.second.second;
			ll distance = dist[now] + nW;
			if (dist[next] > distance && distance < minDist[next]) {
				minDist[next] = distance;
				pq.push({ next, {distance, max(shame, nShame)} });
			}
		}
	}
	if (ans == INF) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> a >> b >> c;
	int f, t, w;
	while (m--) {
		cin >> f >> t >> w;
		v[f].push_back({ t, {w, w} });
		v[t].push_back({ f, {w, w} });
	}
	solve();

	cout << ans;
}