#include <iostream>
using namespace std;

int n;
int useHp[20];
int getHappy[20];

int result[20][101];
int ans;

void solve() {
	if (useHp[0] < 100) {
		result[0][100 - useHp[0]] = getHappy[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (result[i - 1][j] || j == 100) {
				result[i][j] = result[i - 1][j];
				if (j - useHp[i] > 0) {
					if (result[i - 1][j] + getHappy[i] > result[i][j - useHp[i]]) {
						result[i][j - useHp[i]] = result[i - 1][j] + getHappy[i];
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> useHp[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> getHappy[i];
	}

	solve();

	for (int i = 1; i <= 100; i++) {
		if (result[n - 1][i] > ans) {
			ans = result[n - 1][i];
		}
	}
	cout << ans;
}