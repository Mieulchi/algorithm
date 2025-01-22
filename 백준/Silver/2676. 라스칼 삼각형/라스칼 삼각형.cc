#include <iostream>
using namespace std;

int t;
int n, m;

void solve() {
	if (!m) {
		cout << 1 << '\n';
	}
	else if (m == 1) {
		cout << n << '\n';
	}
	else {
		cout << 1 + m * (n - 1 + (n - 1) + -2 * (m - 1)) / 2 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		solve();
	}
}