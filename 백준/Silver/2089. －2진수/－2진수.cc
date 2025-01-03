#include <iostream>
#include <algorithm>
using namespace std;

int n;
string ans;

void solve() {
	int count = 1;

	while (n != 1) {
		int tmp = n / -2;
		if (n - tmp * -2 < 0) {
			tmp++;
		}
		if (n - tmp * -2 == 1) {
			ans += '1';
		}
		else {
			ans += '0';
		}
		n = tmp;
	}
	ans += '1';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	if (n == 0) {
		ans = "0";
	}
	else {
		solve();
	}

	string tmp;
	for (int i = ans.size() - 1; i >= 0; i--) {
		tmp += ans[i];
	}

	cout << tmp;
}