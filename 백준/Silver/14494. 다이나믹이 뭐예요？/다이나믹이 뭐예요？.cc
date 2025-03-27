#include <iostream>
using namespace std;

#define MOD 1000000007

int n, m;
long long dp[1001][1001];
long long ans;

void solve() {
	int x = max(n, m);
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < m; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
		}
	}
	ans = dp[n - 1][m - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve();
	cout << ans;
}