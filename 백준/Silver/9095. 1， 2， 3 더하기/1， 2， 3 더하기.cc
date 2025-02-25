#include <iostream>
using namespace std;

int t;
int n;
int dp[14];

void solve() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 1; i <= 10; i++) {
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
		dp[i + 3] += dp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	solve();
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}