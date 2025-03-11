#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char arr[50][50];
int cnt[50][3];
int dp[50][2];
int ans;

void solve() {
	ans += (m - cnt[0][0]);
	ans += (m - cnt[n - 1][2]);
	dp[1][0] = m - cnt[1][0];
	dp[1][1] = m - cnt[1][1];
	int sum = 0;
	for (int j = 2; j < n - 1; j++) {
		sum += (m - cnt[j][2]);
	}
	int mi = dp[1][1] + sum;
	for (int i = 2; i < n - 1; i++) {
		dp[i][0] = dp[i - 1][0] + (m - cnt[i][0]);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (m - cnt[i][1]);
		sum = 0;
		for (int j = i + 1; j < n - 1; j++) {
			sum += (m - cnt[j][2]);
		}
		if (dp[i][1] + sum < mi) {
			mi = dp[i][1] + sum;
		}
	}
	ans += mi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'W') {
				cnt[i][0]++;
			}
			if (arr[i][j] == 'B') {
				cnt[i][1]++;
			}
			if (arr[i][j] == 'R') {
				cnt[i][2]++;
			}
		}
	}
	solve(); 
	cout << ans;
}