#include <iostream>
using namespace std;

int t;
int a, b;

int solve() {
	int base = a;
	int ret = 1;
	int i = 0;
	while ((1 << i) <= b) {
		if ((b >> i) & 1) {
			ret = (ret * base) % 10;
		}
		base *= base;
		base %= 10;
		i++;
	}
	if (!ret) {
		ret = 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve() << '\n';
	}
}