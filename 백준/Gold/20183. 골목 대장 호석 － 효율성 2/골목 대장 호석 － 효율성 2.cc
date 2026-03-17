#include <iostream>
#include <queue>
#include <climits>
using namespace std;


typedef long long ll;
typedef pair<int, pair<ll, ll>> ppp;

ll INF = LLONG_MAX;
int n, m, a, b;
ll c, ans = INF;

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
		ll shame = front.second.second;

		if (now == b && w <= c) {
			ans = min(ans, shame);
		}

		if (dist[now] < w || w > c) {
			continue;
		}

		dist[now] = w;
		
		for (int i = 0; i < v[now].size(); ++i) {
			ppp p = v[now][i];
			int next = p.first;
			ll nW = p.second.first;
			ll nShame = p.second.second;
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