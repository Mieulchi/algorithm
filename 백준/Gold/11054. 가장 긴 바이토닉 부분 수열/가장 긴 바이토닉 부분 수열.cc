#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[2][1000];
int ans;

void solve() {
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < i; j++) {
			if (dp[0][j] > mx && arr[j] < arr[i]) {
				mx = dp[0][j];
			}
		}
		dp[0][i] = mx + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int mx = 0;
		for (int j = n - 1; j > i; j--) {
			if (dp[1][j] > mx && arr[j] < arr[i]) {
				mx = dp[1][j];
			}
		}
		dp[1][i] = mx + 1;
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[0][i] + dp[1][i] - 1);
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