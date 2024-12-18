#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[100001];
int dp[100001];

long long ans;

void solve() {
	cin >> arr[0];
	
	dp[0] = arr[0];
	ans = dp[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if (dp[i - 1] + arr[i] > + arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}