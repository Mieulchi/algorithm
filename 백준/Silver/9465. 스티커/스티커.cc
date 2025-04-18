#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n;
int arr[2][100000];
int dp[2][100000];
int ans;

void solve() {
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	for (int i = 1; i < n; i++) {
		if (i >= 2) {
			dp[0][i] = max(dp[1][i - 1] + arr[0][i], max(dp[0][i - 2], dp[1][i - 2]) + arr[0][i]);
			dp[1][i] = max(dp[0][i - 1] + arr[1][i], max(dp[0][i - 2], dp[1][i - 2]) + arr[1][i]);
		}
		else {
			dp[0][i] = dp[1][i - 1] + arr[0][i];
			dp[1][i] = dp[0][i - 1] + arr[1][i];
		}
	}
	ans = max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[1][i];
		}
		solve();
		cout << ans << '\n';
	}
}