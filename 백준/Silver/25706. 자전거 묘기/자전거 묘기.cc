#include <iostream>
using namespace std;

int n;
int arr[200001];
int dp[200001];

void solve() {
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] && arr[i] + i >= n) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[i + arr[i] + 1] + 1;
		}
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
	for (int i = 0; i < n; i++) {
		cout << dp[i] << ' ';
	}
}