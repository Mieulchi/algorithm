#include <iostream>
using namespace std;

string s;
int ans;

void solve() {
	int zerocount = 0, onecount = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			onecount++;
			while (i < s.length() && s[i] == '1') {
				i++;
			}
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			zerocount++;
			while (i < s.length() && s[i] == '0') {
				i++;
			}
		}
	}
	ans = zerocount < onecount ? zerocount : onecount;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	solve();
	cout << ans;
}