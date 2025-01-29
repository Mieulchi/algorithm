#include <iostream>
using namespace std;

int n, m;
int square[50][50];
int ans;

void solve() {
	while (ans > 1) {
		int flag = 0;
		for (int i = 0; i <= n - ans; i++) {
			for (int j = 0; j <= m - ans; j++) {
				if (square[i][j] == square[i][j + ans - 1] && square[i][j] == square[i + ans - 1][j] && square[i][j] == square[i + ans - 1][j + ans - 1]) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
		ans--;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	n > m ? ans = m : ans = n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			square[i][j] = s[j] - '0';
		}
	}

	solve();

	cout << ans * ans;
}