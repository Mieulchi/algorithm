#include <iostream>
#include <string>
using namespace std;

int n;
int ans;

void solve() {
	n -= n == 1000 ? 1 : 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			ans++;
		}
		else {
			string s = to_string(i);
			if (s[0] - '0' - s[1] - '0' == s[1] - '0' - s[2] - '0') {
				ans++;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}