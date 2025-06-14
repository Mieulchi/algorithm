#include <iostream>
using namespace std;
#define MOD 1000000007

int s;
string str;
int ans;
int dp[3001][3001];

void solve() {
	for (int i = 0; i < 26; i++) {
		dp[0][i] = 1;
		if (s == i) {
			ans++;
		}
	}

	for (int i = 1; i < str.length(); i++) {
		for (int j = 0; j <= s; j++) {
			for (int k = 0; k < 26; k++) {
				if (j + k <= s) {
					dp[i][j + k] += dp[i - 1][j];
					dp[i][j + k] %= MOD;
				}
			}
		}
	}
	ans = dp[str.length() - 1][s];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> str;
	solve();
	cout << ans;
}