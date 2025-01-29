#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
long long arr[1000001];
long long tree[4000004];
int ans;
int mod = 1000000007;

void make_segTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	else {
		make_segTree(node * 2, start, (start + end) / 2);
		make_segTree(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
		tree[node] %= mod;
	}
}

void update(int node, int idx, int to, int start, int end) {
	if (start > idx || end < idx) {
		return;
	}
	if (idx == start && idx == end) {
		arr[idx] = to;
		tree[node] = to;
		return;
	}
	int mid = (start + end) / 2;
	if (idx <= mid) {
		update(node * 2, idx, to, start, mid);
	}
	else {
		update(node * 2 + 1, idx, to, mid + 1, end);
	}
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
	tree[node] %= mod;
}

long long get(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		int mid = (start + end) / 2;
		return (get(node * 2, start, mid, left, right) * get(node * 2 + 1, mid + 1, end, left, right) % mod);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make_segTree(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c, 1, n);
		}
		else {
			ans = get(1, 1, n, b, c);
			cout << ans << '\n';
		}

	}
}