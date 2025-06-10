#include <iostream>
#include <algorithm>
using namespace std;

int n;
int donghyuk[300000];
int yoonhyeong[300000];
long long ans;
long long minh;
long long maxh = 1000000000000;
long long low, high;

void f() {
	for (int i = 0; i <= n / 2; i++) {
		low += abs(donghyuk[i] - (minh - i));
		low += abs(yoonhyeong[i] - (minh - i));
		high += abs(donghyuk[i] - (maxh - i));
		high += abs(yoonhyeong[i] - (maxh - i));
	}

	for (int i = n / 2 + 1; i < n; i++) {
		low += abs(donghyuk[i] - (minh - (n - i - 1)));
		low += abs(yoonhyeong[i] - (minh - (n - i - 1)));
		high += abs(donghyuk[i] - (maxh - (n - i - 1)));
		high += abs(yoonhyeong[i] - (maxh - (n - i - 1)));
	}
}

void solve() {
	minh = n / 2;

	while (minh <= maxh) {
		if (minh == maxh) {
			low = 0, high = 0;
			f();
			ans = low;
			break;
		}
		low = 0, high = 0;
		f();
		long long mid = (minh + maxh) / 2;

		if (low < high) {
			maxh = mid;
		}
		else {
			minh = mid + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> donghyuk[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> yoonhyeong[i];
	}
	solve();
	cout << ans;
}