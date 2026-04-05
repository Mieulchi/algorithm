#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 10000

int n, k;
int arr[100];
int dp[100][3][2];
int ans;

void solve() {
	arr[0] ? dp[0][arr[0] - 1][0] = 1 : dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = 1;

	for (int i = 1; i < n; ++i) {
		if (arr[i]) {
			for (int j = 0; j < 3; ++j) {
				if (j != arr[i] - 1) {
					dp[i][arr[i] - 1][0] += (dp[i - 1][j][0] + dp[i - 1][j][1]);
					dp[i][arr[i] - 1][0] %= MOD;
				}
				else {
					dp[i][arr[i] - 1][1] += dp[i - 1][j][0];
					dp[i][arr[i] - 1][1] %= MOD;
				}
			}
		}
		else {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					if (j == k) {
						dp[i][j][1] += dp[i - 1][k][0];
						dp[i][j][1] %= MOD;
					}
					else {
						dp[i][j][0] += (dp[i - 1][k][0] + dp[i - 1][k][1]);
						dp[i][j][0] %= MOD;
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans += dp[n - 1][i][j];
			ans %= MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	int a, b;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		arr[a - 1] = b;
	}
	solve();
	cout << ans;
}