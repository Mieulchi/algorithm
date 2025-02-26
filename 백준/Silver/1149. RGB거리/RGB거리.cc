#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000][3];
int ans;

void solve() {
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	int r, g, b;
	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]) + b;
	}
	ans = min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}