#include <iostream>
using namespace std;

int n;
int arr[3000];
int pos[1000001];
long long dp[3000][3000];
long long ans;

void solve() {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int d = arr[i] - arr[j];
			dp[i][j] = arr[i] + arr[j];
			if (arr[j] - d > 0 && pos[arr[j] - d]) {
				dp[i][j] = (arr[i] + dp[j][pos[arr[j] - d] - 1]);
			}
			if (pos[arr[j] - d] && dp[i][j] > ans) {
				ans = dp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		pos[arr[i]] = i + 1;
	}
	solve();
	cout << ans;
}