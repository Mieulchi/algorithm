#include <iostream>
#include <string>
using namespace std;

#define MOD 900528

string s, pw;
long long ans;

long long pow(int co, long long ex) {
	long long base = co;
	long long ret = 1;
	while (ex > 0) {
		if (ex % 2 == 1) {
			ret *= base;
			ret %= MOD;
		}
		base *= base;
		base %= MOD;
		ex /= 2;
	}
	
	return ret;
}

void solve() {
	int len = s.length();
	int pLen = pw.length();

	for (int i = 1; i < pLen; ++i) {
		ans += pow(len, i);
		ans %= MOD;
	}

	long long cnt = 0;
	for (int i = 0; i < pLen; ++i) {
		for (int j = 0; j < len; ++j) {
			if (pw[i] == s[j]) {
				ans += cnt * pow(len, pLen - i - 1);
				cnt = 0;
				ans %= MOD;
				break;
			}
			else {
				++cnt;
			}
		}
	}
	++ans;
	ans %= MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> pw;

	solve();

	cout << ans;
}