#include <iostream>
using namespace std;

int n, s;
int arr[40];
int dp[16000001];
long long ans;

void solve() {
	int k = 1 << (n / 2);
	for (int i = 1; i < k; i++) {
		int sum = 0;
		for (int j = 0; j < n / 2; j++) {
			if ((i >> j) & 1) {
				sum += arr[j];
			}
		}
		if (sum == s) {
			ans++;
		}
		dp[8000000 + sum]++;
	}
	k = 1 << (n - n / 2);
	for (int i = 1; i < k; i++) {
		int sum = 0;
		for (int j = 0; j < n - n / 2; j++) {
			if ((i >> j) & 1) {
				sum += arr[j + n / 2];
			}
		}
		if (sum == s) {
			ans++;
		}
		if (dp[s + 8000000 - sum]) {
			ans += dp[s + 8000000 - sum];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve();

	cout << ans;
}