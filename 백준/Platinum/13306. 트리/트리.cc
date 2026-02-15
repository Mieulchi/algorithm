#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Query {
	int x;
	int a, b;
	Query() : x(0), a(0), b(0) {}
};

int n, q;

int parentNode[200001];
int parent[200001];

Query queries[400000];
vector<string> ans;

void merge(int node) {
	int p = parentNode[node];

	if (parent[p] != parent[node]) {
		parent[node] = parent[p];
	}

}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	parent[a] = find(parent[a]);
	return parent[a];
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	for (int i = n + q - 2; i >= 0; --i) {
		Query query = queries[i];
		if (query.x == 0) {
			merge(query.a);
		}
		else {
			ans.push_back(find(query.a) == find(query.b) ? "YES" : "NO");
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;
	
	parentNode[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> parentNode[i];
	}

	int x, a, b;
	for (int query = 0; query < (n - 1) + q; ++query) {
		cin >> x;

		if (x == 0) {
			cin >> a;
			queries[query].x = x;
			queries[query].a = a;
		}
		//
		else {
			cin >> a >> b;
			queries[query].x = x;

			queries[query].a = a;
			queries[query].b = b;
		}
	}

	solve();

	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << '\n';
	}

}
