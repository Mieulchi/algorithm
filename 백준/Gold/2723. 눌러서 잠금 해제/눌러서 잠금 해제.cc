#include <iostream>
using namespace std;

int n, b;
long long f[12];
long long ans[12];

int comb(int a, int b) {
	int child = 1, parent = 1;
	for (int i = a; i > a - b; i--) {
		child *= i;
	}
	for (int i = b; i >= 1; i--) {
		parent *= i;
	}

	return child / parent;
}

void solve() {
	f[0] = 1;
	for (int i = 1; i <= 11; i++) {
		for (int j = 0; j < i; j++) {
			f[i] += comb(i, j) * f[j];
		}
	}

	for (int i = 1; i <= 11; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i] += comb(i, j) * f[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	solve();

	for (int i = 0; i < n; i++) {
		cin >> b;
		cout << ans[b] << '\n';
	}
}
