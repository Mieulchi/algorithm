#include <iostream>
using namespace std;

int n, m;
bool coins[100][100];
int ans;

void flip(int r, int c) {
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			coins[i][j] = !coins[i][j];
		}
	}
}

void solve() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (coins[i][j]) {
				flip(i, j);
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			s[j] == '1' ? coins[i][j] = 1 : 0;
		}
	}

	solve();

	cout << ans;
}