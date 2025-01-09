#include <iostream>
#include <map>
using namespace std;

int n;
map<long long, int> m;

void solve() {
	for (int i = 0; i < n; i++) {
		long long ans = 0;
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			long long tmp;
			cin >> tmp;
			tmp += 2147483648;
			m[tmp]++;
			if (m[tmp] > (t / 2)) {
				ans = tmp - 2147483648;
			}
		}
		if (ans) {
			cout << ans << '\n';
		}
		else {
			cout << "SYJKGW\n";
		}
		m.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
}