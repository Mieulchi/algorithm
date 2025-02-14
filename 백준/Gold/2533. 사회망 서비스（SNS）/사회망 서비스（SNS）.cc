#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> v[1000001];
int dp[1000001][2];
int visited[1000001];
int ans;

void dfs(int node) {
	visited[node] = 1;
	int cnt = 0;
	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i]]) {
			dfs(v[node][i]);
			dp[node][0] += dp[v[node][i]][1];
			dp[node][1] += min(dp[v[node][i]][0], dp[v[node][i]][1]);
			cnt++;
		}
	}
	dp[node][1]++;
	if (!cnt) {
		dp[node][1] = 1;
		return;
	}
}

void solve() {
	dfs(1);
	ans = min(dp[1][0], dp[1][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	cout << ans;
}