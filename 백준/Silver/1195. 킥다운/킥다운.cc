#include <iostream>
#include <climits>
using namespace std;

string s1;
string s2;
int ans;

void solve() {
	for (int i = 0; i < s2.length(); i++) {
		int flag = 1;
		for (int j = 0; j <= i; j++) {
			if (s1[j] == '2' && s1[j] == s2[s2.length() - 1 - i + j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (ans > s1.length() + s2.length() - i - 1) {
				ans = s1.length() + s2.length() - i - 1;
			}
		}
	}

	for (int i = 0; i < s1.length(); i++) {
		int flag = 1;
		for (int j = i; j < i + s2.length(); j++) {
			if (j >= s1.length()) {
				break;
			}
			if (s2[j - i] == s1[j] && s1[j] == '2') {
				flag = 0;
				break;
			}
		}
		if (flag) {
			int cmp = s1.length();
			if (i + s2.length() > s1.length()) {
				cmp = s2.length() + i;
			}
			if (cmp < ans) {
				ans = cmp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;
	ans = s1.length() + s2.length();
	if (s1.length() < s2.length()) {
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	solve();

	cout << ans;
}