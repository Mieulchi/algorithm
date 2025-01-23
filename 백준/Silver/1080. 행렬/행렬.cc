#include <iostream>
using namespace std;

int n, m;
int mat1[50][50];
int mat2[50][50];
int ans;

void flip(int r, int c) {
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			if (mat1[i][j]) {
				mat1[i][j] = 0;
			}
			else {
				mat1[i][j] = 1;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n- 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (mat1[i][j] != mat2[i][j]) {
				flip(i, j);
				ans++;
			}
		}
	}
	int flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] != mat2[i][j]) {
				flag = 0;
				ans = -1;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			mat1[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			mat2[i][j] = s[j] - '0';
		}
	}
	
	solve();

	cout << ans;
}