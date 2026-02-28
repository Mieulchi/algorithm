#include <iostream>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int n, arr[1001], ans;
int dp[1001][1001];

/*
*
*	O(N^2)
*	1자로 펴봐
*
*	dp[i][j] = i에서 j까지의 최대 쌍의 갯수
* 
* 
*/

void solve() {
	
	//i == size
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= n - i; ++j) {
			dp[j][j + i] = dp[j + 1][j + i - 1] + (arr[j] == arr[j + i] ? 1 : 0);
			for (int k = j; k < j + i; ++k) {
				dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
			}
		}
	}
	ans = dp[1][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	solve();

	cout << ans;
}
