#include <iostream>
using namespace std;

string s, tmp;
char c[26];
int ans;

bool check(int n) {
	string s1 = s;
	for (int i = s.length() - 1 - n; i < s.length() - 1; i++) {
		s1 += tmp[i];
	}
	int mid = s1.length() / 2;
	bool flag = true;
	for (int i = 0; i < mid; i++) {
		if (s1[i] != s1[s1.length() - 1 - i]) {
			return false;
		}
	}

	s = s1;
	return true;
}

void solve() {
	for (int i = s.length() - 2; i >= 0; i--) {
		tmp += s[i];
	}

	for (int i = 0; i <= tmp.length(); i++) {
		if (check(i)) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	if (s.length() != 1) {
		solve();
	}

	ans = s.length();
	cout << ans;
}