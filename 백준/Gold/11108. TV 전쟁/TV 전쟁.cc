#include <iostream>
#include <algorithm>
using namespace std;

int t, n, ans;

struct pg {
	int s;
	int d;
	int p;
};

bool cmp(pg a, pg b) {
	if (a.s + a.d != b.s + b.d) {
		return a.s + a.d < b.s + b.d;
	}
	else {
		return a.s > b.s;
	}
}

pg pgs[100000];
int dp[100000][2];

void solve() {
	sort(pgs, pgs + n, cmp);

	dp[0][1] = pgs[0].p;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		int f = lower_bound(pgs, pgs + n, pgs[i].s, 
			[](const pg& pg, int val) {
			return pg.s + pg.d <= val;
			}
		) - pgs;
		if (pgs[f].s + pgs[f].d == pgs[i].s) {
			dp[i][1] = max(dp[f][0], dp[f][1]) + pgs[i].p;
		}
		else {
			if (!f) {
				dp[i][1] = pgs[i].p;
			}
			else {
				--f;
				dp[i][1] = max(dp[f][0], dp[f][1]) + pgs[i].p;
			}
		}
	}
	ans = max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> pgs[i].s >> pgs[i].d >> pgs[i].p;
		}
		solve();
		cout << ans << '\n';
	}
}