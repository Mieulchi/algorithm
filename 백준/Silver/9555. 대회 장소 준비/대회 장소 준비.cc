#include <iostream>
using namespace std;

int t;
int n, m;
int arr[100][100];
int check[101];
int ans;

void init() {
	for (int i = 1; i <= 100; i++) {
		check[i] = 0;
	}
}

void solve() {
	init();
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {
				if (arr[i][j] == arr[i + 1][j]) {
					check[arr[i][j]] = 1;
				}
				if (j + 1 < m) {
					if (arr[i][j] == arr[i + 1][j + 1]) {
						check[arr[i][j]] = 1;
					}
				}
				if (j - 1 >= 0) {
					if (arr[i][j] == arr[i + 1][j - 1]) {
						check[arr[i][j]] = 1;
					}
				}
			}
			if (i - 1 >= 0) {
				if (arr[i][j] == arr[i - 1][j]) {
					check[arr[i][j]] = 1;
				}
				if (j + 1 < m) {
					if (arr[i][j] == arr[i - 1][j + 1]) {
						check[arr[i][j]] = 1;
					}
				}
				if (j - 1 >= 0) {
					if (arr[i][j] == arr[i - 1][j - 1]) {
						check[arr[i][j]] = 1;
					}
				}
			}
			if (j + 1 < m) {
				if (arr[i][j] == arr[i][j + 1]) {
					check[arr[i][j]] = 1;
				}
			}
			if (j - 1 >= 0) {
				if (arr[i][j] == arr[i][j - 1]) {
					check[arr[i][j]] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (check[i]) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
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