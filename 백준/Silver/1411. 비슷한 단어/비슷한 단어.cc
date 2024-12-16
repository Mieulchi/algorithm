#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long n;
string pattern[100];
int modified[26];

bool mycmp(string s1, string s2) {
	string tmp = s1;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			if (!modified[s2[i] - 'a']) {
				modified[s2[i] - 'a'] = 1;
				char mem = s1[i];
				for (int j = 0; j < s1.length(); j++) {
					if (s1[j] == mem && s1[j] == tmp[j]) {
						s1[j] = s2[i];
					}
				}
			}
			else {
				break;
			}
		}
		else {
			modified[s2[i] - 'a'] = 1;
		}
	}

	for (int i = 0; i < 26; i++) {
		modified[i] = 0;
	}
	if (s1 == s2) {
		return true;
	}
	else {
		return false;
	}
}

void solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pattern[i] = s;

		for (int j = 0; j < i; j++) {
			if (mycmp(s, pattern[j]) && mycmp(pattern[j], s)) {
				ans++;
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
	
}