#include <iostream>
#include <algorithm>
using namespace std;

int mine[750][750];

int dp[750][750][2];

int r, c;
int ans;

//0 1
// x

void solve() {
	if (r <= 2 || c <= 2) {
		return;
	}
	else {
		for (int i = 0; i < c; i++) {
			dp[0][i][0] = mine[0][i];
			dp[0][i][1] = mine[0][i];
		}
		for (int i = 1; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (mine[i][j]) {
					if (j - 1 >= 0) {
						dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
					}
					else {
						dp[i][j][0] = 1;
					}
					if (j + 1 < c) {
						dp[i][j][1] = dp[i - 1][j + 1][1] + 1;
					}
					else {
						dp[i][j][1] = 1;
					}
				}
				else {
					dp[i][j][0] = 0;
					dp[i][j][1] = 0;
				}
			}
		}

		for (int i = r - 1; i >= 0; i--) {
			for (int j = 0; j < c; j++) {
				int t = min(dp[i][j][0], dp[i][j][1]);
				if (t > ans) {
					for (int k = t; k > ans; k--) {
						if (i - k + 1 >= 0 && j - k + 1 >= 0 && j + k - 1 < c) {
							if (dp[i - k + 1][j - k + 1][1] >= k && dp[i - k + 1][j + k - 1][0] >= k) {
								if (k > ans) {
									ans = k;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			mine[i][j] = tmp[j] - '0';
			if (!ans && mine[i][j]) {
				ans = 1;
			}
		}
	}
	if (ans) {
		solve();
	}

	cout << ans;
}