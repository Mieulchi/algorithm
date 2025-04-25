#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int n;
string s;
char ans[10000];
int len;

void solve() {
	memset(ans, ' ', 10000);
	len = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			len++;
		}
	}
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			ans[idx] = toupper(s[i]);
			idx += n;
			if (idx >= len) {
				for (int j = 0; j <= len; j++) {
					if (ans[j] == ' ') {
						idx = j;
						break;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n;
		cin.ignore();
		if (!n) {
			break;
		}
		getline(cin, s);
		solve();
		for (int i = 0; i < len; i++) {
			cout << ans[i];
		}
		cout << '\n';
	}
}