#include <iostream>
using namespace std;

int n, k;
int ans;

void solve() {
	int tmp = k * (k + 1) / 2;
	if (n < tmp) {
		ans = -1;
	}
	else {
		ans = k - 1;
		if ((n - tmp) % k) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << ans;
}