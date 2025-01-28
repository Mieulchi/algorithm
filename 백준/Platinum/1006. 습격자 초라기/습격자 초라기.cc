#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n, w;
int onetagon[10001][2];
int dp[10001][3];
int ans;

void solve() {
	for (int i = 2; i < n; i++) {
		int op1, op2, op3;
		onetagon[i][0] + onetagon[i - 1][0] <= w ? op1 = 1 : op1 = 2;
		onetagon[i][1] + onetagon[i - 1][1] <= w ? op3 = 1 : op3 = 2;
		onetagon[i][0] + onetagon[i][1] <= w ? op2 = 1 : op2 = 2;

		dp[i][0] = min({ dp[i - 2][0] + op1 + op3, dp[i - 1][0] + op2, dp[i - 1][1] + op3, dp[i - 1][2] + op1});
		dp[i][1] = min({ dp[i - 1][0] + 2, dp[i - 1][2] + op1, dp[i - 1][1] + 3 });
		dp[i][2] = min({ dp[i - 1][0] + 2, dp[i - 1][1] + op3, dp[i - 1][2] + 3 });
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> w;
		ans = n * 2;
		for (int j = 1; j <= n; j++) {
			cin >> onetagon[j][0];
		}
		for (int j = 1; j <= n; j++) {
			cin >> onetagon[j][1];
		}
		if (n > 1 && n < 10001) {
			int op1, op2, op3;
			onetagon[1][0] + onetagon[n][0] <= w ? op1 = 1 : op1 = 2;
			onetagon[1][1] + onetagon[n][1] <= w ? op3 = 1 : op3 = 2;
			onetagon[1][0] + onetagon[1][1] <= w ? op2 = 1 : op2 = 2;
			//위 아래 둘다 연결
			if (op1 == 1 && op3 == 1) {
				dp[0][0] = 2;
				dp[1][0] = min(op2 + 2, op1 + op3);
				dp[1][1] = op1 + 2;
				dp[1][2] = op3 + 2;
				solve();
				ans = min({ ans, dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });
				dp[0][0] = 0;
			}
			//위만 연결
			if (onetagon[1][0] + onetagon[n][0] <= w) {
				dp[1][0] = min(op1 + 1, op2 + 1);
				dp[1][1] = op1 + 1;
				dp[1][2] = 3;
				int tmp = onetagon[1][0];
				onetagon[1][0] = 999999;
				solve();
				onetagon[1][0] = tmp;
				int op;
				onetagon[n][1] + onetagon[n - 1][1] <= w ? op = 0 : op = 1;
				ans = min({ ans, dp[n - 1][0] + 1, dp[n - 1][1] + op, dp[n - 1][2] + 1 });
			}
			//아래만 연결
			if (onetagon[1][1] + onetagon[n][1] <= w) { 
				dp[1][0] = min(op2 + 1, op3  + 1);
				dp[1][1] = 3;
				dp[1][2] = op3 + 1;
				int tmp = onetagon[1][1];
				onetagon[1][1] = 999999;
				solve();
				onetagon[1][1] = tmp;
				int op;
				onetagon[n][0] + onetagon[n - 1][0] <= w ? op = 0 : op = 1;
				ans = min({ ans, dp[n - 1][0] + 1, dp[n - 1][1] + 1, dp[n - 1][2] + op });
			}
			//다 연결 안함
			dp[1][0] = op2;
			dp[1][1] = 2;
			dp[1][2] = 2;
			solve();
			onetagon[n][0] + onetagon[n - 1][0] <= w ? op1 = 1 : op1 = 2;
			onetagon[n][1] + onetagon[n - 1][1] <= w ? op3 = 1 : op3 = 2;
			onetagon[n][0] + onetagon[n][1] <= w ? op2 = 1 : op2 = 2;
			dp[n][0] = min({ dp[n - 1][0] + op2, dp[n - 1][1] + op3, dp[n - 1][2] + op1, dp[n - 2][0] + op1 + op3});
			dp[n][1] = min({ dp[n - 1][1] + 3, dp[n - 1][2] + op1 });
			dp[n][2] = min({ dp[n - 1][1] + op3, dp[n - 1][2] + 3 });
			ans = min({ ans, dp[n][0], dp[n][1], dp[n][2] });
		}
		else {
			if (onetagon[1][0] + onetagon[1][1] <= w) {
				ans = 1;
			}
			else {
				ans = 2;
			}
		}
		cout << ans << '\n';
	}
}