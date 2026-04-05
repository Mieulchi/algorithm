#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, ans;
int arr[1000][1000];

//dp[i][j] = i행 j열에서의 최대 정사각형 크기
int dp[1000][1000];

void solve() {

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < m; ++j) {
			if (arr[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
		for (int j = 1; j < m; ++j) {
			if (arr[j][i] == 1) {
				dp[j][i] = min({ dp[j - 1][i], dp[j][i - 1], dp[j - 1][i - 1] }) + 1;
				ans = max(ans, dp[j][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j]) {
				ans = 1;
				dp[i][j]++;
			}
		}
	}
	solve();

	cout << ans * ans;
}