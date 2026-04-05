#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, k;
int ans;

void solve() {
	while (true) {
		int cnt = 0;
		int i = 0;
		while ((1 << i) <= n) {
			if ((n >> i) & 1) {
				++cnt;
			}
			++i;
		}
		if (cnt <= k) {
			break;
		}

		i = 0;
		while (true) {
			if ((n >> i) & 1) {
				ans += (1 << i);
				n += (1 << i);
				break;
			}
			++i;
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