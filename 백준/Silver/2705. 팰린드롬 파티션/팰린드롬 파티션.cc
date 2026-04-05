#include <iostream>
#include <algorithm>
using namespace std;

int t, n, ans;
int dp[1000];

void solve() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 1001; ++i) {
		dp[i] = 1;
		for (int j = 1; j <= i / 2; ++j) {
			int op = i - j * 2;
			if (op >= 0) {
				dp[i] += dp[j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	solve();
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}