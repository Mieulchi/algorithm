#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2000000000

int n;
string a, b;
int p1, p3, p5, pp;
int ans;

int dp[2005][2005];

void solve() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] != INF) {
				if (i < n) {
					if (a[i] == '0') {
						dp[min(n, i + 1)][j] = min(dp[min(n, i + 1)][j], dp[i][j]);
					}
					else {
						dp[min(n, i + 1)][j] = min(dp[min(n, i + 1)][j], dp[i][j] + p1);
						dp[min(n, i + 3)][j] = min(dp[min(n, i + 3)][j], dp[i][j] + p3);
						dp[min(n, i + 5)][j] = min(dp[min(n, i + 5)][j], dp[i][j] + p5);
					}
				}
				if (j < n) {
					if (b[j] == '0') {
						dp[i][min(n, j + 1)] = min(dp[i][min(n, j + 1)], dp[i][j]);
					}
					else {
						dp[i][min(n, j + 1)] = min(dp[i][min(n, j + 1)], dp[i][j] + p1);
						dp[i][min(n, j + 3)] = min(dp[i][min(n, j + 3)], dp[i][j] + p3);
						dp[i][min(n, j + 5)] = min(dp[i][min(n, j + 5)], dp[i][j] + p5);
					}
				}
				if (i < n || j < n) {
					int f = min(i, j);
					int t = f + 4;
					int nextI = min(n, max(i, t));
					int nextJ = min(n, max(j, t));
					dp[nextI][nextJ] = min(dp[nextI][nextJ], dp[i][j] + pp);
				}
			}
		}
	}
	ans = dp[n][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> p1 >> p3 >> p5 >> pp;
	solve();
	cout << ans;
}