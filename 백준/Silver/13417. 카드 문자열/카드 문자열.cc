#include <iostream>
using namespace std;

int t;
int n;
string ans;

void solve() {
	cin >> ans;
	char c;
	for (int i = 1; i < n; i++) {
		cin >> c;
		if (c > ans[0]) {
			ans += c;
		}
		else {
			ans = c + ans;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		solve();
		cout << ans << '\n';
	}
}