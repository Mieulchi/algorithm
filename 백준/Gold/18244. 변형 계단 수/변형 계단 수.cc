#include <iostream>
using namespace std;

#define MOD 1000000007

int n;
//dp[i][j][k][l] = i번째자리가 j로 시작하며 k개 연속으로 증감한 수. l이 증감 방향
//1 증가 0 감소
long long dp[100][10][3][2];
long long  ans;

void solve() {
	for (int i = 0; i < 10; ++i) {
		dp[0][i][0][0] = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j - 1 >= 0) {
				//1개 증가
				dp[i][j][1][1] += dp[i - 1][j - 1][0][0];
				dp[i][j][1][1] %= MOD;

				dp[i][j][1][1] += dp[i - 1][j - 1][1][0];
				dp[i][j][1][1] %= MOD;

				dp[i][j][1][1] += dp[i - 1][j - 1][2][0];
				dp[i][j][1][1] %= MOD;

				//2개 증가
				dp[i][j][2][1] += dp[i - 1][j - 1][1][1];
				dp[i][j][2][1] %= MOD;
			}
			if (j + 1 < 10) {
				//1개 감소
				dp[i][j][1][0] += dp[i - 1][j + 1][0][0];
				dp[i][j][1][0] %= MOD;

				dp[i][j][1][0] += dp[i - 1][j + 1][1][1];
				dp[i][j][1][0] %= MOD;

				dp[i][j][1][0] += dp[i - 1][j + 1][2][1];
				dp[i][j][1][0] %= MOD;


				//2개 감소
				dp[i][j][2][0] += dp[i - 1][j + 1][1][0];
				dp[i][j][2][0] %= MOD;

			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans += dp[n - 1][i][0][j];
			ans += dp[n - 1][i][1][j];
			ans += dp[n - 1][i][2][j];
			ans %= MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}