#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Tree {
	int parent[18];
	int depth;
	Tree() : parent(), depth(0) {}
};

vector<int> v[100001];
int visited[100001];
Tree tree[100001];

void dfs(int node, int depth) {
	if (visited[node]) {
		return;
	}
	visited[node] = 1;
	tree[node].depth = depth;

	for (int i = 0; i < v[node].size(); ++i) {
		int next = v[node][i];
		if (!visited[next]) {
			tree[next].parent[0] = node;
			dfs(v[node][i], depth + 1);
		}
	}
}

int find(int a, int b) {

	while (tree[a].depth != tree[b].depth) {
		if (tree[a].depth > tree[b].depth) {
			int diff = tree[a].depth - tree[b].depth;
			int step = 1;
			while ((1 << step) <= diff) {
				++step;
			}
			--step;
			a = tree[a].parent[step];
		}
		else {
			int diff = tree[b].depth - tree[a].depth;
			int step = 1;
			while ((1 << step) <= diff) {
				++step;
			}
			--step;
			b = tree[b].parent[step];
		}
	}

	if (a == b) {
		return a;
	}

	for (int i = 17; i >= 0; --i) {

		if (tree[a].parent[i] != tree[b].parent[i]) {
			a = tree[a].parent[i];
			b = tree[b].parent[i];
		}
	}

	return tree[a].parent[0];
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

	dfs(1, 1);

	for (int k = 1; k < 18; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (tree[i].parent[k - 1]) {
				tree[i].parent[k] = tree[tree[i].parent[k - 1]].parent[k - 1];
			}
		}
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << find(a, b) << '\n';
	}
}
