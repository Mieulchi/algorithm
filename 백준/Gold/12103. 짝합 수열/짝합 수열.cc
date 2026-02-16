#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, k;
long long arr[1000002];
bool odd[1000001];
int dp[1000001][2];
int ans;

/*
	arr[i] === arr[i + k] (MOD 2) WTF
*/

void solve() {
	for (int i = 1; i <= k; ++i) {
		for (int j = i; j <= n; j += k) {
			dp[i][arr[j] % 2]++;
		}
	}

	int checkSum = 0;
	int diff = INF;
	int idx = 0;
	for (int i = 1; i <= k; ++i) {
		
		odd[i] = dp[i][0] < dp[i][1] ? 1 : 0;
		ans += min(dp[i][0], dp[i][1]);

		if (odd[i]) {
			checkSum++;
		}

		int nowDiff = abs(dp[i][0] - dp[i][1]);
		if (nowDiff < diff) {
			diff = nowDiff;
			idx = i;
		}
	}

	if (checkSum % 2) {
        ans += diff;
		odd[idx] = odd[idx] == 1 ? 0 : 1;
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = i; j <= n; j += k) {
			if (arr[j] % 2 != odd[i]) {
				arr[j]++;
                
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	solve();
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << arr[i] << ' ';
	}
}
