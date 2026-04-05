#include <iostream>
using namespace std;

typedef long long ll;

int n;
//켜져있는 스위치 수 저장
int tree[400004];
//버튼 누른 횟수 저장
int lazy[400004];

void update_lazy(int node, int s, int e) {
	if (lazy[node] % 2) {
		tree[node] = (e - s + 1) - tree[node];
		if (s != e) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);

	if (r < s || e < l) {
		return;
	}

	if (l <= s && e <= r) {
		tree[node] = (e - s + 1) - tree[node];
		if (s != e) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l, r);
	update(node * 2 + 1, mid + 1, e, l, r);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);

	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return tree[node];
	}
	
	int mid = (s + e) / 2;

	return find(node * 2, s, mid, l, r) + find(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> n >> m;

	int query, l, r;
	while (m--) {
		cin >> query >> l >> r;
		if (query == 0) {


			update(1, 1, n, l, r);
		}
		else {
			cout << find(1, 1, n, l, r) << '\n';
		}
	}
}