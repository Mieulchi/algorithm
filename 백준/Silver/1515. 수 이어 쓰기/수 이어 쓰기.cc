#include <iostream>
#include <string>
using namespace std;

string s;
string cmp;
int ans;

void solve() {
	ans = 1;
	cmp = "1";
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		while (true) {
			int flag = 1;
			for (int j = index; j < cmp.length(); j++) {
				if (cmp[j] == s[i]) {
					flag = 0;
					index = j + 1;
					break;
				}
			}
			if (flag) {
				ans++;
				index = 0;
				cmp = to_string(ans);
			}
			else {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> s;
	solve();
	cout << ans << '\n';
}