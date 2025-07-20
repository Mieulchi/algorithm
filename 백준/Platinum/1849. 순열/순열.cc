#include <iostream>
using namespace std;

int n;
int ans[100001];
int tree[400004];

void find(int node, int s, int e, int f, int i) {
	tree[node]--;
	if (s == e) {
		ans[s] = i;
	}
	else {
		int mid = (s + e) / 2;
		if (tree[node * 2] >= f) {
			find(node * 2, s, mid, f, i);
		}
		else {
			find(node * 2 + 1, mid + 1, e, f - tree[node * 2], i);
		}
	}
}

void init(int node, int s, int e) {
	if (s == e) {
		if (s > 1) {
			tree[node]++;
		}
		return;
	}
	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve() {
	init(1, 1, n);
	for (int i = 1; i <= n; i++) {
		ans[i] = i - 1;
	}
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		find(1, 1, n, t, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}