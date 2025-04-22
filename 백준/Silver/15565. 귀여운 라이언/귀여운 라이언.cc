#include <iostream>
using namespace std;

int n, k;
int dp[1000000];
int ans;

void solve() {
	int left = 1, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		for (int i = 0; i <= n - mid; i++) {
			if (i == 0) {
				if (dp[i + mid - 1] >= k) {
					ans = mid;
					break; 
				}
			}
			else {
				if (dp[i + mid - 1] - dp[i - 1] >= k) {
					ans = mid;
					break;
				}
			}
		}
		if (ans != mid) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (ans == 0) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	int t;
	cin >> t;
	if (t == 1) {
		dp[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		cin >> t;
		dp[i] = dp[i - 1] + (t == 1 ? 1 : 0);
	}
	solve();
	cout << ans;
}