#include <iostream>
using namespace std;

#define MOD 1000000007

int t;
string s;
long long ans;

bool isMoeum(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

void solve() {
	int cnt = 0;
	int moeum = 0;
	ans = 1;
	for (int i = 0; i < s.length(); i++) {
		if (isMoeum(s[i])) {
			moeum++;
			if (moeum != 1) {
				ans *= (cnt + 1);
				ans %= MOD;
			}
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	if (!moeum) {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> s;
		solve();
		cout << ans << '\n';
	}
}