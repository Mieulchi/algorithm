#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, D;
long long arr[100001];
long long tree[400004];
long long ans = LLONG_MIN;

void add(int node, int s, int e, int key, long long value) {
	if (s == e && s == key) {
		tree[node] = value;
		return;
	}
	int mid = (s + e) / 2;
	if (key <= mid) {
		add(node * 2, s, mid, key, value);
	}
	else {
		add(node * 2 + 1, mid + 1, e, key, value);
	}
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

long long find(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return LLONG_MIN;
	}
	if (l <= s &&  e <= r) {
		return tree[node];
	}
	int mid = (s + e) / 2;
	return max(find(node * 2, s, mid, l, r), find(node * 2 + 1, mid + 1, e, l, r));
}

void solve() {
	for (int i = 1; i <= 4 * N; i++) {
		tree[i] = LLONG_MIN;
	}
	add(1, 1, N, 1, arr[1]);
	ans = arr[1];

	for (int i = 2; i <= N; i++) {
		int left = max(1, i - D);
		long long m = find(1, 1, N, left, i - 1);
		long long value = arr[i] + max(m, 0LL);
		add(1, 1, N, i, value);
		ans = max(ans, value);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> D;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}