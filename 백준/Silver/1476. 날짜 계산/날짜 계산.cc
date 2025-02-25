#include <iostream>
#include <algorithm>
using namespace std;

int e, s, m;
int ans;

void solve() {
	while (true) {
		if (e == s && s == m) {
			ans += e;
			break;
		}
		e = (e + 14) % 15;
		s = (s + 27) % 28;
		m = (m + 18) % 19;
		if (!e) e += 15;
		if (!s) s += 28;
		if (!m) m += 19;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> e >> s >> m;
	solve();
	cout << ans;
}