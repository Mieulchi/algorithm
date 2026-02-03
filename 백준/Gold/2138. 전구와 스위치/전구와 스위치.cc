#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string a, b, c;
int ans;

void solve() {

	c = a;
	a[0] = (a[0] - '0') ? '0' : '1';
	a[1] = (a[1] - '0') ? '0' : '1';
	++ans;

	for (int i = 1; i < n - 1; ++i) {
		if (a[i - 1] != b[i - 1]) {
			a[i - 1] = (a[i - 1] - '0') ? '0' : '1';
			a[i] = (a[i] - '0') ? '0' : '1';
			a[i + 1] = (a[i + 1] - '0') ? '0' : '1';
			++ans;
		}
	}
	if (b[n - 2] != a[n - 2]) {
		a[n - 2] = (a[n - 2] - '0') ? '0' : '1';
		a[n - 1] = (a[n - 1] - '0') ? '0' : '1';
		++ans;
	}

	if (b[n - 1] != a[n - 1]) {
		ans = -1;
	}


	int tmp = 0;

	for (int i = 1; i < n - 1; ++i) {
		if (c[i - 1] != b[i - 1]) {
			c[i - 1] = (c[i - 1] - '0') ? '0' : '1';
			c[i] = (c[i] - '0') ? '0' : '1';
			c[i + 1] = (c[i + 1] - '0') ? '0' : '1';
			++tmp;
		}
	}
	if (b[n - 2] != c[n - 2]) {
		c[n - 2] = (c[n - 2] - '0') ? '0' : '1';
		c[n - 1] = (c[n - 1] - '0') ? '0' : '1';
		++tmp;
	}


	if (b[n - 1] != c[n - 1]) {
		tmp = -1;
	}
	if (ans != -1 || tmp != -1) {
		if (ans == -1) {
			ans = tmp;
		}
		else if (tmp == -1) {

		}
		else {
			ans = min(ans, tmp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cin >> a;
	cin >> b;

	solve();

	cout << ans;
}