#include <iostream>
#include <algorithm>
using namespace std;

int l, n;
string s;
int cnt[200001];

void solve() {
	for (int i = 0; i < l; i++) {
		if (s[i] == 'w') {
			if (i) {
				cnt[i] = cnt[i - 1] + 1;
			}
			else {
				cnt[i]++;
			}
		}
		else if (s[i] == 'h') {
			if (i) {
				cnt[i] = cnt[i - 1];
			}
			int idx = i - min(cnt[i], n);
			swap(s[i], s[idx]);
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