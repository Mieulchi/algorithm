#include <iostream>
using namespace std;

int n;

int board[100][100];
long long dp[100][100];

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!dp[i][j] || !board[i][j]) {
				continue;
			}
			if (j + board[i][j] < n) {
				dp[i][j + board[i][j]] += dp[i][j];
			}
			if (i + board[i][j] < n) {
				dp[i + board[i][j]][j] += dp[i][j];
			}
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = 1;
	solve();
	
	cout << dp[n - 1][n - 1];
}