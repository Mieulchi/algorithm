#include <iostream>
#include <string>
using namespace std;

int n;
long long ans;
string anns;

long long parse(long long m) {
	while (m % 10 == 0) {
		m /= 10;
	}
	return m;
}

void solve() {
	ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans = parse(ans);
		ans %= 1000000000000;
	}
	string s = to_string(ans);
	string tmp;
	int len = s.length();
	if (s.length() >= 5) {
		for (int j = len - 5; j <= len - 1; j++) {
			tmp += s[j];
		}
	}
	else {
		for (int j = 0; j <= len; j++) {
			tmp += s[j];
		}
	}
	anns = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << anns;
}