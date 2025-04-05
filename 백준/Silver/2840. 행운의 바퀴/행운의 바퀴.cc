#include <iostream>
using namespace std;

int n, k;
int s;
char c;
char arr[25];
int dup[26];
int now;
int flag;
string ans;

void solve() {
	while (k--) {
		cin >> s >> c;
		now = (now + s) % n;
		if (arr[now]) {
			if (c != arr[now]) {
				flag = 1;
			}
		}
		else {
			if (dup[c - 'A']) {
				flag = 1;
			}
			else {
				dup[c - 'A'] = 1;
			}
		}
		arr[now] = c;
	}
	if (flag) {
		ans = '!';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!arr[(now + (n - i)) % n]) {
				ans += '?';
			}
			else {
				ans += arr[(now + (n - i)) % n];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	
	solve();

	cout << ans;
}