#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001][3];

//i번째 포함 세 명의 상태가 j일 때, 요원인지/아닌지에 따른 만족도
int dp[1000001][8];

int ans;

void solve() {
	for (int i = 0; i <= n; ++i) {
		fill(dp[i], dp[i] + 8, -1000000007);
	}

	for (int i = 0; i < 8; ++i) {
		if (i >> 2 & 1) {

			if (i % 2) {
				dp[2][i] = 0;
			}
			else {
				dp[2][i] = (i >> 1) & 1 ? 0 : arr[2][2];
			}
		}
	}
	
	for (int i = 3; i <= n; ++i) {

		for (int j = 0; j < 8; ++j) {
			int bits[3];

			bits[0] = ((j >> 2) & 1);
			bits[1] = ((j >> 1) & 1);
			bits[2] = ((j >> 0) & 1);

			int sum = 0;
			for (int k = 0; k < 3; ++k) {
				if (!(bits[k])) {
					sum += arr[i][k];
				}
			}

			for (int k = 0; k < 2; ++k) {
				int nextBit = ((j << 1) & 6) + k;
				if (k == 0) {
					dp[i][nextBit] = max(dp[i][nextBit], dp[i - 1][j] + sum);
				}
				else {
					dp[i][nextBit] = max(dp[i][nextBit], dp[i - 1][j]);
				}
			}
		}
	}
	for (int i = 0; i < 8; ++i) {
		ans = max({ ans, dp[n][i]});
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	solve();

	cout << ans;
 }
