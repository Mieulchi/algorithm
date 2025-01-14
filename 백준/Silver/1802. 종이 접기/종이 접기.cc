#include <iostream>
#include <map>
using namespace std;

int n;
string s;
string ans;

void dev_conq(int from, int to) {
	if (from == to) {
		return;
	}
	int flag = 1;
	int len = (from + to) / 2;
	for (int i = from; i < len; i++) {
		if ((s[i] - '0') + (s[to - 1 - i] - '0') != 1) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		dev_conq(from, len);
		dev_conq(len + 1, to);
	}
	else {
		ans = "NO";
	}
}

void solve() {
	ans = "YES";
	cin >> s;

	dev_conq(0, s.length());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		solve();
		cout << ans << '\n';
	}
}