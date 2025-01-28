#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans;

void solve() {
	int min6 = 5000, min1 = 5000;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (min6 > a) {
			min6 = a;
		}
		if (min1 > b) {
			min1 = b;
		}
	}

	if (min1 * 6 < min6) {
		ans += n * min1;
	}
	else {
		ans += (n / 6) * min6;
		if (n % 6) {
			if (n % 6 * min1 < min6) {
				ans += n % 6 * min1;
			}
			else {
				ans += min6;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();
	cout << ans << '\n';

}