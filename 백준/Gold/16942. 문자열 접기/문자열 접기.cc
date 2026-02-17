#include <iostream>
#include <algorithm>
using namespace std;

string s;

int ans;

void solve() {
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		int cnt = 1;
		int prev = i;
		for (int j = i + 1; j < len; ++j) {
			if (s[j] == s[i] && (j - prev) % 2) {
				cnt++;
				prev = j;
			}
		}
		ans = max(ans, cnt);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	solve();

	cout << ans;
 }
