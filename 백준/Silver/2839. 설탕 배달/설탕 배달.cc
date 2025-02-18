#include <iostream>
using namespace std;

int n;
int dp[5001];

void recursive(int i) {
	if (i + 3 <= n && (!dp[i + 3] || dp[i + 3] > dp[i] + 1)) {
		dp[i + 3] = dp[i] + 1;
		recursive(i + 3);
	}
	if (i + 5 <= n && (!dp[i + 5] || dp[i + 5] > dp[i] + 1)) {
		dp[i + 5] = dp[i] + 1;
		recursive(i + 5);
	}
}

void solve() {
	dp[3] = 1;
	dp[5] = 1;
	recursive(3);
	recursive(5);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
	if (!dp[n]) {
		dp[n] = -1;
	}
	cout << dp[n];
}