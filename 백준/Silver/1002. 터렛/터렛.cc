#include <iostream>
#include <string>
using namespace std;

void solve() {
	int x1, y1, x2, y2, r1, r2;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	int op = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (r2 > r1) {
		int tmpr = r1;
		r1 = r2;
		r2 = tmpr;
	}

	if (x1 == x2 && y1 == y2) {
		if (r1 == r2) {
			cout << -1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	else {
		if (op > r1 * r1) {
			int op2 = (r1 + r2) * (r1 + r2);
			if (op > op2) {
				cout << 0 << '\n';
			}
			else if (op == op2) {
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		else if (op < r1 * r1) {
			int op2 = (r1 - r2) * (r1 - r2);
			if (op2 > op) {
				cout << 0 << '\n';
			}
			else if (op2 == op) {
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		else {
			cout << 2 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		solve();
	}
	
}