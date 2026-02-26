#include <iostream>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int n, l, r;

/*
* 
* i에서 j높이인 빌딩이 특정 순서 k로 보이기 위해서는?
* i - 1번째에서 j보다 낮은 빌딩이 k - 1번째로 보여야 함
* -> O(N^5) 정도면 풀릴텐데, 시간초과
* dp[][i][j][k] = 첫 인덱스의 상태에 따라, i위치에서 j높이 빌딩이 k번째로 보일 수 있는 경우의 수
* 
* 
* -> 단방향에서, dp[i][j] = n - i번째로 작은 빌딩을 세울 때 j개 보이는 경우의 수.
*  점화식 : dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * (i - 1)
* 
*/

ll dp[101][101][101];
ll ans;

void solve() {
	dp[1][1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {

				dp[i][j][k] += dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
				dp[i][j][k] %= MOD;

				dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
				dp[i][j][k] %= MOD;
			}
		}
	}

	ans = dp[n][l][r];

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;

	solve();

	cout << ans;
}
