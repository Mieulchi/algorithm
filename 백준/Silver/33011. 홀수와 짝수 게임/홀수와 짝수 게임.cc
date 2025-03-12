#include <iostream>
using namespace std;

int t, n;
string ans;
int cnt[2];

void solve() {
	if (cnt[1] < cnt[0]) {
		swap(cnt[0], cnt[1]);
	}
	if (cnt[1] > cnt[0]) {
		ans = cnt[1] % 2 ? "amsminn" : "heeda0528";
	}
	else {
		ans = "heeda0528";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cnt[1] = 0, cnt[0] = 0;
		cin >> n;
		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			k % 2 ? cnt[0]++ : cnt[1]++;
		}
		solve();
		cout << ans << '\n';
	}
}