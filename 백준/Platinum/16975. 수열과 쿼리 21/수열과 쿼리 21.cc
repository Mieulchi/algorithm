#include <iostream>
using namespace std;

typedef long long ll;

int n;
int arr[100001];
ll tree[400004];
ll lazy[400004];

void make_tree(int node, int s, int e) {
	if (s == e) {
		tree[node] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	make_tree(node * 2, s, mid);
	make_tree(node * 2 + 1, mid + 1, e);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (ll)(e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int l, int r, int v) {
	update_lazy(node, s, e);

	if (r < s || e < l) {
		return;
	}

	if (l <= s && e <= r) {
		tree[node] += (ll)(e - s + 1) * v;
		if (s != e) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}

		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l, r, v);
	update(node * 2 + 1, mid + 1, e, l, r, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


ll find(int node, int s, int e, int idx) {
	update_lazy(node, s, e);

	if (s == e) {
		return tree[node];
	}

	int mid = (s + e) / 2;
	if (idx <= mid) {
		return find(node * 2, s, mid, idx);
	}
	else {
		return find(node * 2 + 1, mid + 1, e, idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	make_tree(1, 1, n);

	int m;
	cin >> m;

	int query;
	while (m--) {
		cin >> query;

		int a, b, c;
		if (query == 1) {
			cin >> a >> b >> c;

			update(1, 1, n, a, b, c);
		}
		else {
			cin >> a;
			cout << find(1, 1, n, a) << '\n';
		}
	}
}