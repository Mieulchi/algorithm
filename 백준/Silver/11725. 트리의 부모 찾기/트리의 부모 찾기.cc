#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[100001];
int visited[100001];
int ans[100001];

void dfs(int idx) {
	visited[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visited[v[idx][i]]) {
			ans[v[idx][i]] = idx;
			dfs(v[idx][i]);
		}
	}
}

void solve() {
	visited[1] = 1;
	dfs(1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();
	
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}