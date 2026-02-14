#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Tree {
	int parent;
	int depth;
	Tree() : parent(0) {}
};

vector<int> v[50001];
int visited[50001];
Tree tree[50001];

void dfs(int node, int depth) {
	if (visited[node]) {
		return;
	}
	visited[node] = 1;
	tree[node].depth = depth;

	for (int i = 0; i < v[node].size(); ++i) {
		if (!visited[v[node][i]]) {
			tree[v[node][i]].parent = node;
			dfs(v[node][i], depth + 1);
		}
	}
}

void init() {
	dfs(1, 1);
}

int find(int a, int b) {

	while (tree[a].depth != tree[b].depth) {
		if (tree[a].depth < tree[b].depth) {
			b = tree[b].parent;
		}
		else {
			a = tree[a].parent;
		}
	}

	while (true) {
		if (a == b) {
			return a;
		}
		b = tree[b].parent;
		a = tree[a].parent;
		
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	init();

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << find(a, b) << '\n';
	}
}
