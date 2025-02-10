#include <iostream>
using namespace std;

int n, b;
long long dp[12];
long long ans[12];

int nCr(int n, int r) {
	int child = 1, parent = 1;
	for (int i = n; i > n - r; i--) {
		child *= i;
	}
	for (int i = r; i > 0; i--) {
		parent *= i;
	}
	return child / parent;
}

void solve() {
	dp[0] = 1;
	for (int i = 1; i <= 11; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += nCr(i, j) * dp[j];
		}
	}
	for (int i = 1; i <= 11; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i] += nCr(i, j) * dp[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
	for (int i = 0; i < n; i++) {
		cin >> b;
		cout << ans[b] << '\n';
	}
}