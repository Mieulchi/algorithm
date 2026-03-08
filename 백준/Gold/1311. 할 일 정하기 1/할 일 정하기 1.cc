#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, ans;
int arr[20][20];
int dp[21][1 << 20];
int cnt[1 << 20];
//dp[i][mask] = i번 사람까지 이미 일을 햇을 때에 mask 상태를 만족하는 상태의 최소 비용

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

	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << n); ++mask) {
			if (cnt[mask] == i) {
				for (int j = 0; j < n; ++j) {
					int prev = mask - (1 << j);
					if (prev >= 0 && dp[i - 1][prev] != INF) {
						dp[i][mask] = min(dp[i][mask], dp[i - 1][prev] + arr[i - 1][j]);
					}
				}
			}
		}
		
	}
	ans = dp[n][(1 << n) - 1];

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
		for (int mask = 0; mask < (1 << n); ++mask) {
			dp[i][mask] = INF;
		}
	}

	solve();

	cout << ans;
}