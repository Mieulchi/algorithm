#include <iostream>
using namespace std;

#define MOD 1000000007

int n, k;
long long dp[3001];
long long ans;

void solve() {
	dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1 + dp[i - 2] * 2;
		dp[i] %= MOD;
	}

	if (k % 2 == 0) {
		ans += n % 2 ? 1 : -1;
	}
	ans += dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	
	solve();

	cout << ans;
}