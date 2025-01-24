#include <iostream>
using namespace std;

int x;
int n, m;
void solve() {
	int i = 0;
	int cnt = 1;
	while (true) {
		if (i + cnt >= x) {
			cnt++;
			break;
		}
		i += cnt;
		cnt++;
	}
	if (cnt % 2) {
		n += x - i;
		m += cnt - (x - i);
	}
	else {
		m += x - i;
		n += cnt - (x - i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x;

	solve();

	cout << n << '/' << m;
}