#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000000];
int dp[1000000];
int ans;

void solve() {

	int idx = 0;
	dp[0] = arr[0];
	for (int i = 0; i < n; ++i) {

		if (dp[idx] < arr[i]) {
			dp[++idx] = arr[i];
		}
		else {
			int find = lower_bound(dp, dp + idx, arr[i]) - dp;
			dp[find] = arr[i];
		}
	}
	ans = idx + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	solve();

	cout << ans;
}
