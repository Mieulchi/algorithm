#include <iostream>
#include <queue>
using namespace std;

int n, m, ans;
vector<int> v[2001];

int visited[2001];

void dfs(int node, int turn) {
	if (!ans) {
		return;
	}
	visited[node] = turn;

	int nextStep = turn == 2 ? 1 : 2;

	for (int i = 0; i < v[node].size(); ++i) {
		int next = v[node][i];
		if (visited[next] == 0) {
			dfs(next, nextStep);
		}
		else {
			if (visited[next] == turn) {
				ans = 0;
				return;
			}
		}
	}

	return;
}

void solve() {

	ans = 1;

	for (int i = 1; i <= n; ++i) {
		if (!ans) {
			break;
		}
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	cout << ans;
}