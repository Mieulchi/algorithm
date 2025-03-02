#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int c1[26];
int c2[26];
string ans;

void init() {
	for (int i = 0; i < 26; i++) {
		c1[i] = 0;
		c2[i] = 0;
	}
}

void solve() {
	init();
	for (int i = 0; i < a.length(); i++) {
		c1[a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		c2[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		int k = min(c1[i], c2[i]);
		for (int j = 0; j < k; j++) {
			ans += i + 'a';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (getline(cin, a) && getline(cin, b)) {
		ans = "";
		solve();
		cout << ans << '\n';
	}
}