#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int m, n;
string s[100];

string convert(string t) {
	string tmp;
	for (int j = 0; j < t.length(); j++) {
		if (t[j] == '0') {
			tmp += "zero";
		}
		if (t[j] == '1') {
			tmp += "one";
		}
		if (t[j] == '2') {
			tmp += "two";
		}
		if (t[j] == '3') {
			tmp += "three";
		}
		if (t[j] == '4') {
			tmp += "four";
		}
		if (t[j] == '5') {
			tmp += "five";
		}
		if (t[j] == '6') {
			tmp += "six";
		}
		if (t[j] == '7') {
			tmp += "seven";
		}
		if (t[j] == '8') {
			tmp += "eight";
		}
		if (t[j] == '9') {
			tmp += "nine";
		}
	}
	return tmp;
}

bool cmp(string s1, string s2) {
	s1 = convert(s1);
	s2 = convert(s2);
	return s1 < s2;
}
void solve() {
	string t;
	for (int i = 0; i <= n - m; i++) {
		s[i] = to_string(i + m);
	}
	sort(s, s + n - m + 1, cmp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	solve();
	for (int i = 0; i <= n - m; i++) {
		cout << s[i] << ' ';
		if (i && (i + 1) % 10 == 0) {
			cout << '\n';
		}
	}
}