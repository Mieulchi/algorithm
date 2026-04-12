#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<long long, int> pp;

int n, m, q;
vector<pp> edges[5];
unordered_map<string, vector<int>> um;

int parent[50001];

int sequence[5];
pp arr[5];
long long ans;

int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa != pb) {
		parent[pa] = pb;
	}
}

void f() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	string key;
	
	vector<int> v;
	for (int i = 0; i < 5; ++i) {
		key += ('0' + sequence[i]);
		int cnt = 0;
		for (pp edge : edges[sequence[i]]) {
			int a = edge.first;
			int b = edge.second;

			if (find(a) != find(b)) {
				merge(a, b);
				cnt++;
			}

		}
		v.push_back(cnt);

	}
	um.insert({ key, v });

}

void dfs(int depth, int mask) {
	if (depth != 5) {
		for (int i = 0; i < 5; ++i) {
			if ((mask >> i) & 1) {
				continue;
			}
			sequence[depth] = i;
			dfs(depth + 1, mask | (1 << i));
		}
	}
	else {
		f();
	}
}

void preprocess() {
	dfs(0, 0);
}

void solve() {
	sort(arr, arr + 5);
	string key;
	for (int i = 0; i < 5; ++i) {
		key += (arr[i].second + '0');
	}
	ans = 0;

	vector<int> v = um[key];
	for (int i = 0; i < 5; ++i) {
		ans += arr[i].first * v[i];
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> q;

	int a, b;
	char ch;
	while (m--) {
		cin >> a >> b >> ch;
		edges[ch - 'A'].push_back({ a, b });
	}

	preprocess();

	while (q--) {
		for (int i = 0; i < 5; ++i) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		solve();
		cout << ans << '\n';
	}
}