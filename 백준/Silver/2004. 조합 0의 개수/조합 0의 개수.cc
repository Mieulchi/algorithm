#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long ans;

void solve() {
	long long a5 = 0, b5 = 0;
	long long a2 = 0, b2 = 0;
	if (n - m < m) {
		m = n - m;
	}
	long long i = 5;
	while (i <= n) {
		a5 += (n / i) - (n - m) / i;
		b5 += m / i;
		i *= 5;
	}

	i = 2;
	while (i <= n) {
		a2 += (n / i) - (n - m) / i;
		b2 += m / i;
		i *= 2;
	}

	ans = min(a5 - b5, a2 - b2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << ans;
}