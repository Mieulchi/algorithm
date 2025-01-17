#include <iostream>
using namespace std;

string l, r;
int ans;

void solve() {
	for (int i = 0; i < l.length(); i++) {
		if (l[i] == r[i] && l[i] == '8') {
			ans++;
		}
		else {
			if (l[i] != r[i]) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> r;

	if (l.length() != r.length()) {
		ans = 0;
	}
	else {
		solve();
	}
	cout << ans;
}