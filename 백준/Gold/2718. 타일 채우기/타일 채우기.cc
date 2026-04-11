#include <iostream>
using namespace std;

typedef pair<int, int> pp;

int dp[31][6];

void solve() {
	dp[0][0] = 1;
	for (int i = 1; i <= 30; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][3];
		dp[i][3] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][4] = dp[i - 1][0] + dp[i - 1][5];
		dp[i][5] = dp[i - 1][4];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][0] << '\n';
	}
}