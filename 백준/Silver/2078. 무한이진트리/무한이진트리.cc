#include <iostream>
using namespace std;

int n, m;
int l, r;

void solve() {
	while (n != 1 && m != 1) {
		if (n > m) {
			l += n / m;
			n %= m;
		}
		else {
			r += m / n;
			m %= n;
		}
	}
	if (n == 1) {
		r += m - 1;
	}
	else {
		l += n - 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << l << ' ' << r;
}