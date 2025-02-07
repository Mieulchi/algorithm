#include <iostream>
#include <algorithm>
using namespace std;

long long x, y, w, s;
long long ans;

void solve() {
	if (w * 2 <= s) {
		ans = x * w + y * w;
	}
	else {
		if (x == y) {
			ans = s * x;
		}
		else {
			if (x > y) {
				if (w > s) {
					int op = x - y;
					if (op % 2) {
						ans += (op / 2) * s * 2 + w;
					}
					else {
						ans += (op / 2) * s * 2;
					}
				}
				else {
					ans += (x - y) * w;
				}
			}
			else {
				if (w > s) {
					int op = y - x;
					if (op % 2) {
						ans += (op / 2) * s * 2 + w;
					}
					else {
						ans += (op / 2) * s * 2;
					}
				}
				else {
					ans += (y - x) * w;
				}
			}
			ans += min(x, y) * s;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> w >> s;

	solve();

	cout << ans;

}