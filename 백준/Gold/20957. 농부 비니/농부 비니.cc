#include <iostream>
using namespace std;

#define MOD 1000000007

int t, n;
long long dp[10001][7][2];

void solve() {
	for (int i = 1; i < 10; ++i) {
		int t = i == 7 ? 1 : 0;
		++dp[1][i % 7][t];
	}

	for (int i = 2; i < 10001; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 7; ++k) {
				int op = (j + k) % 7;
				dp[i][op][1] += dp[i - 1][k][1];
				dp[i][op][1] %= MOD;

				if (j == 7 || j == 0) {
					dp[i][op][1] += dp[i - 1][k][0];
					dp[i][op][1] %= MOD;
				}
				else {
					dp[i][op][0] += dp[i - 1][k][0];
					dp[i][op][0] %= MOD;
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
		cin >> n;
		cout << dp[n][0][1] << '\n';
	}
}