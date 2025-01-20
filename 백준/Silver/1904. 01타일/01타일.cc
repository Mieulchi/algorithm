#include <iostream>
using namespace std;

int n;
long long ans;

void solve() {
	int n1 = 1, n2 = 2;
	for (int i = 3; i <= n; i++) {
		ans = n1 + n2;
		n1 = n2;
		n2 = ans;
		if (n1 > 15746) {
			n1 %= 15746;
		}
		if (n2 > 15746) {
			n2 %= 15746;
		}
	} 
	if (ans >= 15746) {
		ans %= 15746;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;

	if (n <= 2) {
		ans = n;
	}
	else {
		solve();
	}

	cout << ans << '\n';

}