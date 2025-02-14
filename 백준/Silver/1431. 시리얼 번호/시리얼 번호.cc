#include <iostream>
#include <algorithm>
using namespace std;

int w, n;
string s[50];

bool cmp(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	else {
		int sumS1 = 0, sumS2 = 0;
		int len = s1.length();
		int op1, op2;
		for (int i = 0; i < len; i++) {
			op1 = s1[i] - '0';
			if (op1 > 0 && op1 <= 9) {
				sumS1 += op1;
			}
			op2 = s2[i] - '0';
			if (op2 > 0 && op2 <= 9) {
				sumS2 += op2;
			}
		}
		if (sumS1 != sumS2) {
			return sumS1 < sumS2;
		}
		else {
			for (int i = 0; i < len; i++) {
				if (s1[i] != s2[i]) {
					return s1[i] < s2[i];
				}
			}
		}
	}
}

void solve() {
	sort(s, s + n, cmp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	solve();

	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}
}