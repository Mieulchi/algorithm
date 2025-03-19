#include <iostream>
#include <string>
using namespace std;

int cnt;
string ans = "YES";

void solve() {
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	if (sum < 10) {
		if (sum % 3 != 0) {
			ans = "NO";
		}
		return;
	}
	cnt++;
	s = to_string(sum);

	while (stoi(s) >= 10) {
        sum = 0;
		for (int i = 0; i < s.length(); i++) {
			sum += s[i] - '0';
		}
		if (sum % 3 != 0) {
			ans = "NO";
		}
		s = to_string(sum);
		cnt++;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	cout << cnt << '\n' << ans;
}