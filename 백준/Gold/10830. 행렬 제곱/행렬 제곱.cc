#include <iostream>
using namespace std;


long long n, b;
int mat[5][5];
int result[5][5];
int tmp[5][5];

void matOnce() {
	int tmp[5][5] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += result[i][k] * mat[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = tmp[i][j];
		}
	}
}

void matSquare() {
	int tmp[5][5] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += result[i][k] * result[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = tmp[i][j];
		}
	}
}

void solve() {
	string s = "";
	while (b > 1) {
		if (b % 2 == 1) {
			s += '1';
			b--;
		}
		s += '0';
		b /= 2;
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			matOnce();
		}
		else {
			matSquare();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			mat[i][j] %= 1000;
			result[i][j] = mat[i][j];
		}
	}

	if (n > 1) {
		solve();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}