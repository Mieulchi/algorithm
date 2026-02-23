#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int ans = 0;
	int cnt = 1;
	int prev = s[0] - '0';
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] - '0' - 1 == prev) {
			++cnt;
		}
		else {
			if (cnt == 3) ans++;
			cnt = 1;
		}
		prev = s[i] - '0';
	}
	if (cnt == 3) ans++;
	cout << ans;
}
