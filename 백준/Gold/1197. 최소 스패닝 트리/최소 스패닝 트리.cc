#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007
#define edge pair<pair<int, int>, int>
int V, E;

edge edges[100000];
int parent[10001];
int ans;

int find(int u) {
	if (parent[u] == u) {
		return u;
	}

	return parent[u] = find(parent[u]);
}

void join(int a, int pa, int b, int pb) {
	parent[pb] = pa;
}


bool cmp(edge e1, edge e2) {
	return e1.second < e2.second;
}

void solve() {
	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}
	sort(edges, edges + E, cmp);

	int cnt = 0;
	for (int i = 0; i < E; ++i) {
		int a = edges[i].first.first;
		int b = edges[i].first.second;
		
		int pa = find(a);
		int pb = find(b);
		if (pa != pb) {
			join(a, pa, b, pb);
			ans += edges[i].second;
			++cnt;
		}
		if (cnt == V - 1) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { {a, b}, c };
	}
	solve();
	cout << ans;
}