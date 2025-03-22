#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int man[1001];
int woman[1001];
long long dp[1001][1001];
int ans;

void solve() {
	sort(man + 1, man + n + 1);
	sort(woman + 1, woman + m + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) {
				dp[i][j] = dp[i - 1][j - 1] + abs(man[i] - woman[j]);
			}
			else if (i > j) {
				dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i] - woman[j]), dp[i - 1][j]);
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i] - woman[j]), dp[i][j - 1]);
			}
		}
	}
	ans = dp[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> man[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> woman[i];
	}
	solve();
	cout << ans;
}