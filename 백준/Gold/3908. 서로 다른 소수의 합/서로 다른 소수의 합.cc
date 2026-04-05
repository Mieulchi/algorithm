#include <iostream>
using namespace std;

int t, n, k;

int prime[1121];
int dp[1121][15];

void solve() {
	for (int i = 2; i < 1121; ++i) {
		if (!prime[i]) {
			for (int j = i * 2; j < 1121; j += i) {
				prime[j] = 1;
			}
		}
	}

	dp[0][0] = 1;
	for (int i = 2; i < 1121; ++i) {
		if (!prime[i]) {
			for (int j = 1120; j >= i; --j) {
				for (int k = 14; k > 0; --k) {
					dp[j][k] += dp[j - i][k - 1];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	cin >> t;
	while (t--) {
		cin >> n >> k;

		cout << dp[n][k] << '\n';
	}
}