#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s;
vector<int> graph[1001];
int visited[1001];

void dfs(int v) {
	cout << v << ' ';
	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i]);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	cout << v << ' ';
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();

		visited[v] = 1;
		for (int i = 0; i < graph[vertex].size(); i++) {
			if (!visited[graph[vertex][i]]) {
				cout << graph[vertex][i] << ' ';
				visited[graph[vertex][i]] = 1;
				q.push(graph[vertex][i]);
			}
		}

	}
}
void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
	}
}

void solve() {
	dfs(s);
	cout << '\n';
	init();
	bfs(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	solve();
}