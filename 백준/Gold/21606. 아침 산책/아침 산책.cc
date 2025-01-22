#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n;
int inout[200001];
vector<int> v[200001];
int ans;
int visited[200001];
int cnt;
queue<int> q;

void dfs(int s, int start) {
	visited[s] = 1;
	if (s != start && inout[s]) {
		cnt++;
		q.push(s);
		return;
	}
	for (int i = 0; i < v[s].size(); i++) {
		if (!visited[v[s][i]]) {
			dfs(v[s][i], start);
		}
		if (s == start) {
			ans += cnt * (cnt + 1);
			cnt = 0;
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		if (inout[i] == 1 && !visited[i]) {
			q.push(i);
			break;
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		dfs(i, i);
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

	cout << ans;
}