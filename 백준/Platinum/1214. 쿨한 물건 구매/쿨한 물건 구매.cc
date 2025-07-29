#include <iostream>
using namespace std;

int d, p, q;
int ans;

void solve() {
	if (p < q) {
		int tmp = q;
		q = p;
		p = tmp;
	}
	for (int i = 0; i < q && i <= d / p + 1; i++) {
		int res = i * p;
		if (d - res > 0) {
			res += ((d - (i * p)) / q) * q;
		}
		res += res < d ? q : 0;
		if (!ans || ans > res) {
			ans = res;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d >> p >> q;
	solve();
	cout << ans;
}