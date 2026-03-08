#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, ans;
int arr[20][20];
int dp[1 << 20];
int cnt[1 << 20];

void solve() {
	for (int mask = 0; mask < (1 << n); ++mask) {
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				count++;
			}
		}
		cnt[mask] = count;
	}

	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int num = cnt[mask] - 1;

		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				int prev = mask & ~(1 << i);

				dp[mask] = min(dp[mask], dp[prev] + arr[num][i]);
			}
		}
		

	}
	ans = dp[(1 << n) - 1];

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
	for (int mask = 0; mask < (1 << n); ++mask) {
		dp[mask] = INF;
	}


	solve();

	cout << ans;
}