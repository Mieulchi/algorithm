#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long ans;
long long a, b;

void solve() {
	long long i = 5;
	while (i <= n) {
		a = a + (n / i) - (n - m) / i - m / i;
		i *= 5;
	}
	i = 2;
	while (i <= n) {
		b = b + (n / i) - (n - m) / i - m / i;
		i *= 2;
	}
	ans = min(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << ans;
}