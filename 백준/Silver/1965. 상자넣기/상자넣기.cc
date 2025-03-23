#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int ans = 1;

void solve() {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}