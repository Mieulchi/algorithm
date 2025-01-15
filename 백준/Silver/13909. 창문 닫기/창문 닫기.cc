#include <iostream>
using namespace std;

int n;
int ans;

void solve() {
	for (int i = 1; i < n; i++) {
		if (i * i < n) {
			ans++;
		}
		else {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n == 1) {
		ans = 1;
	}
	else {
		solve();
	}

	cout << ans;
}