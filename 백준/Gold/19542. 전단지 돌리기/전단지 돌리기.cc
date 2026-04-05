#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, d;
vector<int> v[100001];
int depth[100001];
int ans;

int dfs(int node, int before) {
	for (int i = 0; i < v[node].size(); i++) {
		if (v[node][i] != before) {
			depth[node] = max(depth[node], dfs(v[node][i], node) + 1);
		}
	}
	if (depth[node] >= d && s != node) {
		ans++;
	}
	return depth[node];
}

void solve() {
	dfs(s, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s >> d;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();
	cout << ans * 2;
}