#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000007

int n, ans = INF, p;
int arr[16][16];
string s;
int dp[17][1 << 16];
vector<int> v[17];

void solve() {
	for (int j = 0; j < (1 << n); ++j) {
		int cnt = 0;
		for (int k = 0; k < n; ++k) {
			if ((j >> k) & 1) {
				++cnt;
			}
		}
		v[cnt].push_back(j);
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < v[i - 1].size(); ++j) {
			int prv = v[i - 1][j];
			for (int k = 0; k < n; ++k) {
				if ((prv >> k) & 1) {
					for (int l = 0; l < n; ++l) {
						if (k != l  && ((prv >> l) & 1) == 0) {
							int next = prv + (1 << l);
							dp[i][next] = min(dp[i][next], dp[i - 1][prv] + arr[k][l]);
							if (i >= p) {
								ans = min(ans, dp[i][next]);
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

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			dp[i][j] = INF;
		}
	}

	cin >> s;
	int flag = 0;
	int cnt = 0;
    int bitmask = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'Y') {
			flag = 1;
			bitmask += (1 << i);
			++cnt;
		}
	}
    dp[cnt][bitmask] = 0;
	cin >> p;

	if (cnt < p) {
		if (flag) {
			solve();
		}
		else {
			ans = -1;
		}
	}
	else {
		ans = 0;
	}

	cout << ans;
}