#include <iostream>
#include <vector>
using namespace std;

int c;
int n, m;
char arr[10][10];
int dp[10][1024];
vector<int> table[1024];
int ans;

void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 1024; j++) {
			dp[i][j] = 0;
		}
	}

}

void solve() {
	int bm = 1 << n;
	init();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < bm; j++) {
			for (int k = 0; k < n; k++) {
				if (((j >> k) & 1) && arr[k][i] == '.') {
					dp[i][j]++;
				}
			}
			if (i) {
				int tmp = dp[i][j];
				for (int k = 0; k < table[j].size(); k++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][table[j][k]] + tmp);
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < bm; i++) {
		if (dp[m - 1][i] > ans) {
			ans = dp[m - 1][i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < (1 << 10); j++) {
			int flag = 1;
			for (int k = 0; k < 10; k++) {
				if ((i >> k) & 1) {
					if ((j >> k) & 1) {
						flag = 0;
						break;
					}
					if (k == 0) {
						if ((j >> 1) & 1) {
							flag = 0;
							break;
						}
					}
					else if (k == 9) {
						if ((j >> 8) & 1) {
							flag = 0;
							break;
						}
					}
					else {
						if ((j >> (k + 1)) & 1) {
							flag = 0;
							break;
						}
						if ((j >> (k - 1)) & 1) {
							flag = 0;
							break;
						}
					}
				}
			}
			if (flag) {
				table[i].push_back(j);
			}
		}
	}

	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
		cout << ans << '\n';
	}
}