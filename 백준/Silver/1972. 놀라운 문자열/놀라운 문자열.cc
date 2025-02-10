#include <iostream>
#include <map>
using namespace std;

string s;
map<string, int> m;

void solve() {
	int flag = 1;
	for (int i = 0; i < s.length() - 1 && flag; i++) {
		for (int j = 0; j < s.length() - i - 1; j++) {
			string tmp = "";
			tmp += s[j];
			tmp += s[j + i + 1];
			if (m[tmp]) {
				flag = 0;
				break;
			}
			m[tmp] = 1;
		}
		m.clear();
	}
	cout << s << " is " << (flag ? "" : "NOT ") << "surprising.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> s;
		if (s == "*") break;
		solve();
	}
}