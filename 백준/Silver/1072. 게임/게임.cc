#include <iostream>
using namespace std;

long long x, y, z;
long long ans;

void solve() {
	long long left = 0;
	long long right = 1000000001;
	long long z = (y * 100) / x;
	ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;

		long long now = (y + mid) * 100 / (x + mid);
		if (now != z) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	solve();
	cout << ans;
}