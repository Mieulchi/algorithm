#include <iostream>
using namespace std;

int n, k;
int ans;

//dp[i][j][k] = 길이 i인수열에서 인접한 1이 j개고 k로 끝나는 경우의 수

int dp[101][101][2];

void solve() {
	dp[1][0][0] = dp[1][0][1] = 1;
	for (int i = 2; i <= 100; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] += dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << '\n';
	}
}