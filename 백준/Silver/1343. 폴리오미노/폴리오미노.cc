#include <iostream>
using namespace std;

string s;
string ans;

void solve() {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'X') {
			cnt++;
			if (cnt == 4) {
				ans += "AAAA";
				cnt = 0;
			}
		}
		else {
			if (cnt == 0 || cnt == 2) {
				ans += cnt == 2 ? "BB." : ".";
				cnt = 0;
			}
			else {
				ans = "-1";
				break;
			}
		}
	}
	if (ans != "-1") {
		if (cnt == 2 || cnt == 0) {
			ans = cnt == 2 ? ans + "BB" : ans;
		}
		else {
			ans = "-1";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	solve();
	cout << ans;
}