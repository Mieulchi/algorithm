#include <iostream>
#include <cmath>
using namespace std;

long long n;
long long ans = 1;

void solve() {
	int m = (int)sqrt(n);
	for (int i = 2; i <= m; i++) {
		int cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		if (cnt) {
			long long mul = 1;
			for (int j = 0; j < cnt; j++) {
				mul *= i;
			}
			ans *= (mul - mul / i);
		}
	}
	if (n > 1) {
		ans *= (n - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}