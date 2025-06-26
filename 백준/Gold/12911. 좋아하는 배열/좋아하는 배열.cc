#include <iostream>
using namespace std;
#define MOD 1000000007

int n, k;
int dp[10][100001];
int sum[10];
int ans;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (!i) {
				dp[i][j] = 1;
				sum[i]++;
			}
			else {
				dp[i][j] = sum[i - 1];
				long long tmp = 0;
				for (int l = j * 2; l <= k; l += j) {
					tmp += dp[i - 1][l];
					tmp %= MOD;
				}

				dp[i][j] -= tmp;
				if (dp[i][j] < 0) {
					dp[i][j] += MOD;
				}
				
				sum[i] += dp[i][j];
				sum[i] %= MOD;
			}
		}
	}
	ans = sum[n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << ans;
} 