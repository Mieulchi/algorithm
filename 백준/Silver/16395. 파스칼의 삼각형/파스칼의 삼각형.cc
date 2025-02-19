#include <iostream>
using namespace std;

int n, k;
int ans;

void solve() {
	n--; k--;
	if (n - k < k) {
		k = n - k;
	}
	long long parent = 1;
	long long div = 1;
	for (int i = n; i > n - k; i--) {
		parent *= i;
	}
	for (int i = k; i > 0; i--) {
		div *= i;
	}
	ans = parent / div;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	if (n == 1) {
		ans = 1;
	}
	else {
		solve();
	}

	cout << ans;
}