#include <iostream>
#include <algorithm>
using namespace std;

long long t, n;

void solve() {
	if (n < 6) {
		cout << n;
	}
	else {
		long long m = n / 6;
		long long sum = 0;
		for (int i = 0; i <= m; i++) {
			sum += i;
		}
		long long remain = n - m * 6;

		long long ans = 0;
		ans += sum * 6 + remain + 1;
		
		if (remain) {
			if (remain == 1) {
				ans += m - 1;
			}
			else if (remain == 2) {
				ans += (2 * m - 1) ;
			}
			else if (remain == 3) {
				ans += (2 * m - 1) + m;
			}
			else if (remain == 4) {
				ans += (2 * m - 1) + 2 * m;
			}
			else {
				ans += (2 * m - 1) * 2 + m + 1;
			}
		}

		cout << ans;
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	solve();
}