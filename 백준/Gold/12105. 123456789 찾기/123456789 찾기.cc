#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MOD 1000000007
typedef long long ll;

string p, s;
ll ans;

bool arr[10000];
ll dp[10001][48];

//12 / 4 / 2 / 1

int getCnt(int n, int div) {
	int cnt = 0;
	while (n && n % div == 0) {
		n /= div;
		cnt++;
	}
	return cnt;
}

void solve() {
	int pL = p.length();
	int sL = s.length();

	for (int i = 0; i <= sL - pL; ++i) {
		string str;
		for (int j = i; j < i + pL; ++j) {
			str += s[j];
		}
		if (str == p) {
			arr[i] = 1;
		}
	}

	if (arr[0]) {
		dp[0][0]++;
	}

	for (int i = 1; i <= sL - pL; ++i) {
		for (int j = 0; j < 48; ++j) {
			dp[i][j] = dp[i - 1][j];
		}

		if (arr[i]) {
			int cnt2 = min(3, getCnt(i + 1, 2));
			int cnt3 = min(2, getCnt(i + 1, 3));
			int cnt5 = min(1, getCnt(i + 1, 5));
			int cnt7 = min(1, getCnt(i + 1, 7));

			int next = 12 * cnt2 + 4 * cnt3 + 2 * cnt5 + cnt7;
			dp[i][next]++;

			for (int j = 0; j < 48; ++j) {
				int cpy = j;
				int prev2 = cpy / 12;
				cpy %= 12;
				int prev3 = cpy / 4;
				cpy %= 4;
				int prev5 = cpy / 2;
				cpy %= 2;
				int prev7 = cpy;
				next = 12 * min(prev2 + cnt2, 3) + 4 * min(prev3 + cnt3, 2) + 2 * min(prev5 + cnt5, 1) +  min(prev7 + cnt7, 1);
				
				dp[i][next] += dp[i - 1][j];
				dp[i][next] %= MOD;
			}
		}
	}
	ans = dp[sL - pL][47];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> p >> s;

	solve();

	cout << ans;
}