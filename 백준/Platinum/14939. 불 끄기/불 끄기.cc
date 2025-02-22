#include <iostream>
using namespace std;

int ans;
short arr[10][10];
short cpy[10][10];
int cnt;

void flip(int r, int c) {
	cpy[r][c] = cpy[r][c] ? 0 : 1;
	if (c + 1 < 10) {
		cpy[r][c + 1] = cpy[r][c + 1] ? 0 : 1;
	}
	if (c - 1 >= 0) {
		cpy[r][c - 1] = cpy[r][c - 1] ? 0 : 1;
	}
	if (r + 1 < 10) {
		cpy[r + 1][c] = cpy[r + 1][c] ? 0 : 1;
	}
	if (r - 1 >= 0) {
		cpy[r - 1][c] = cpy[r - 1][c] ? 0 : 1;
	}
}

void mycpy() {
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			cpy[j][k] = arr[j][k];
		}
	}
}

void init(int bitmask) {
	cnt = 0;
	for (int j = 0; j < 10; j++) {
		if (((bitmask >> j) & 1) ^ cpy[0][9 - j]) {
			flip(0, 9 - j);
			cnt++;
		}
	}
}

void flipAll() {
	for (int j = 0; j < 9; j++) {
		for (int k = 0; k < 10; k++) {
			if (cpy[j][k]) {
				flip(j + 1, k);
				cnt++;
			}
		}
	}
}
bool check() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (cpy[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	int m = 1 << 10;
	for (int i = 0; i < m; i++) {
		mycpy();
		init(i);
		flipAll();
		if (check()) {
			if (!ans || ans > cnt) {
				ans = cnt;
			}
		}
		
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	for (int i = 0; i < 10; i++) {
		cin >> s;
		for (int j = 0; j < 10; j++) {
			arr[i][j] = s[j] == 'O' ? 1 : 0;
		}
	}

	solve();

	cout << ans;
}