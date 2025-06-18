#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long long, int> tree;
long long ans;
long long mx = 1LL << 60;

void solve(long long node) {
	if (node >= mx) {
		ans = -1;
		return;
	}
	if (tree[node]) {
		return;
	}
	else {
		if (ans != -1) {
			ans++;
			solve(node * 2);
			solve(node * 2 + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	long long t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		tree[t] = 1;
	}
	solve(1);
	cout << ans;
}