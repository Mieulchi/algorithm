#include <iostream>
#include <string>
using namespace std;

long long k;

long long dp[100];

string ans;

void solve() {
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < 100; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}


	while (k) {

		long long cnt = 0;

		for (int i = 1; i < 100; ++i) {
			cnt += dp[i];

			if (cnt >= k) {
				if (ans == "") {
					ans = "1";
					for (int j = 1; j < i; ++j) {
						ans += '0';
					}
				}
				else {
					ans[ans.length() - i] = '1';
				}
				k -= (cnt - dp[i] + 1);
				break;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	solve();

	cout << ans;
}