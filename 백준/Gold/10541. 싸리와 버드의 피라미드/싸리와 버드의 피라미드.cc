#include <iostream>
using namespace std;

long long n, a;
string s;
int k;
char c;
long long ans;
int cnt[1000002][26];

void solve() {
	ans = 0;
	int len = s.length();

	//t가 카운트 시작 위치
	int t;
	if (a % 2 == 0) {
		t = (((a - 1) % len) * ((a / 2) % len)) % len;
	}
	else {
		t = ((((a - 1) / 2) % len) * (a % len)) % len;
	}

	int p = c - 'A';
	if (t + a <= len) {
		ans += cnt[t + a - 1][p];
		if (t - 1 >= 0) {
			ans -= cnt[t - 1][p];
		}
	}
	else {
		ans += cnt[len - 1][p];
		if (t - 1 >= 0) {
			ans -= cnt[t - 1][p];
		}
		long long left = a - len + t;
		ans += cnt[len - 1][p] * (left / len);
		if (left % len - 1 >= 0) {
			ans += cnt[left % len - 1][p];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s >> k;
	cnt[0][s[0] - 'A']++;
	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			cnt[i][j] = cnt[i - 1][j];
		}
		cnt[i][s[i] - 'A']++;
	}
	while (k--) {
		cin >> a >> c;
		solve();
		cout << ans << '\n';
	}
}