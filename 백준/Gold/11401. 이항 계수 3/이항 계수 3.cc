#include <iostream>
using namespace std;

#define MOD 1000000007

int n, k;
long long ans;

long long factorial(int n) {
	long long ret = 1;

	for (int i = 1; i <= n; i++) {
		ret *= i;
		ret %= MOD;
	}

	return ret;
}

void solve() {
	ans = factorial(n);
	long long base = factorial(n - k) * factorial(k) % MOD;

	int tmp = MOD - 2;
	long long res = 1;
	while (tmp) {
		if (tmp & 1) {
			res = (res * base) % MOD;
		}
		base *= base;
		base %= MOD;
		tmp /= 2;
	}
	ans = ans * res % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << ans;
}