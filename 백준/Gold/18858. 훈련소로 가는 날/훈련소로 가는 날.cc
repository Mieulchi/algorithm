#include <iostream>
using namespace std;

#define MOD 998244353

int n, m;
long long ans;

long long dp[1001][101][2];

void solve() {
	for (int i = 1; i <= m; ++i) {
		dp[1][i][0] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= m; ++k) {
				if (k > j) {
					dp[i][j][0] += dp[i - 1][k][0];
					dp[i][j][0] %= MOD;
				}
				else {
					if (k < j) {
						dp[i][j][1] += dp[i - 1][k][0];
						dp[i][j][1] += dp[i - 1][k][1];
						dp[i][j][1] %= MOD;
					}
					else {
						dp[i][j][0] += dp[i - 1][k][0];
						dp[i][j][0] += dp[i - 1][k][1];
						dp[i][j][0] %= MOD;
					}
				}

			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		ans += (dp[n][i][0] + dp[n][i][1]);
		ans %= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve();
	cout << ans;
}