#include <iostream>
#include <vector>
using namespace std;

int n;
int inout[200001];
vector<int> v[200001];
int ans;
int visited[200001];
int start;

void init() {
	for (int i = 0; i < 200001; i++) {
		visited[i] = 0;
	}
}

void dfs(int s) {
	if (visited[s]) {
		return;
	}

	visited[s] = 1;

	if (inout[s] == 1 && s != start) {
		ans++;
	}
	else {
		for (int i = 0; i < v[s].size(); i++) {
			if (v[s][i] != start) {
				dfs(v[s][i]);
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		if (inout[i] == 1) {
			start = i;
			dfs(i);
		}
		init();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		inout[i] = s[i - 1] - '0';
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	cout<<ans;
}