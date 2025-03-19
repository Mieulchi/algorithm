#include <iostream>
#include <map>
using namespace std;

int n;
int lineA[500001];
int lineB[500001];
map<int, int> m;
int tree[2000001];
long long ans;

int add(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return 0;
	}
	if (l <= s && r >= e) {
		return tree[node];
	}
	int mid = (s + e) / 2;
	return add(node * 2, s, mid, l, r) + add(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int s, int e, int idx) {
	if (s > idx || e < idx) {
		return;
	}
	if (s <= idx && idx <= e) {
		tree[node]++;
	}
	int mid = (s + e) / 2;
	if (s != e) {
		update(node * 2, s, mid, idx);
		update(node * 2 + 1, mid + 1, e, idx);
	}

}

void solve() {
	for (int i = 1; i <= n; i++) {
		ans += add(1, 1, n, m[lineA[i]] + 1, n);
		update(1, 1, n, m[lineA[i]]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lineA[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> lineB[i];
		m[lineB[i]] = i;
	}
	solve();
	cout << ans;
}