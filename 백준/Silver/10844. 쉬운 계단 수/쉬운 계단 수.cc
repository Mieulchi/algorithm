#include <iostream>
using namespace std;

int n;
long long dp[101][10];
long long ans;

void solve() {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j + 1 < 10) {
				dp[i][j] += dp[i - 1][j + 1];
			}
			if (j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1];
			}

			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	ans %= 1000000000;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}