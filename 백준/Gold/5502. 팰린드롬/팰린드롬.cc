#include <iostream>
#include <algorithm>
using namespace std;

int dp[5000];
int n, ans;
string s;

int f(int a, int b) {
	return a - b > 0 ? a - b : b - a;
}

void solve() {
	int len = s.length();
	for (int i = len - 2; i >= 0; i--) {
		int prev = 0;
		for (int j = i + 1; j < len; j++) {
			int tmp = dp[j];
			if (s[i] == s[j]) {
				dp[j] = prev;
			}
			else {
				dp[j] = 1 + min(dp[j], dp[j - 1]);
			}
			prev = tmp;
		}
	}
	ans = dp[len - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> s;
	solve();
	cout << ans;
}