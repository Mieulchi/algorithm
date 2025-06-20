#include <iostream>
#include <algorithm>
using namespace std;

int l, n;
string s;

void solve() {
	int cnt = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] == 'w') {
			cnt++;
		}
		else if (s[i] == 'h') {
			int idx = i - min(cnt, n);
			swap(s[i], s[idx]);
		}
		else {
			cnt = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> n >> s;
	solve();
	cout << s;
}