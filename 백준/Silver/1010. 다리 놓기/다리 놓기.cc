#include <iostream>
using namespace std;

int t;
int n, m;
long long ans;

void solve() {
	if (n > m / 2) {
		n = m - n;
	}
	ans = 1;
	int div = 1;
	for (int i = m; i > m - n; i--) {
		ans *= i;
		ans /= div;
		div++;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		solve();
		cout << ans << '\n';
	}
}