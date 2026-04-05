#include <iostream>
#include <algorithm>
using namespace std;

string s;
int ans;

int last;
int dp[26][2];

void solve() {
	int len = s.length();

	int prevl, prevr;
	for (int i = 0; i < 26; ++i) {
		int cnt = 0;
		int l = 51, r = -1;
		for (int j = 0; j < len; ++j) {
			if (s[j] == 'a' + i) {
				if (j < l) {
					l = j;
				}
				if (j > r) {
					r = j;
				}
				++cnt;
			}
		}
		if (cnt) {
			int tmp = r - l + cnt;
			if (!i) {
				dp[0][0] = r + (r - l) + cnt;
				dp[0][1] = r + cnt;
			}
			else {
				dp[i][0] = min(dp[last][1] + abs(prevr - r) + tmp, dp[last][0] + abs(prevl - r) + tmp);
				dp[i][1] = min(dp[last][1] + abs(prevr - l) + tmp, dp[last][0] + abs(prevl - l) + tmp);
			}
			last = i;
			prevl = l;
			prevr = r;
		}
	}
	ans = min(dp[last][0], dp[last][1]);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	solve();
	cout << ans;
}