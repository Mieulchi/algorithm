#include <iostream>
#include <cmath>
using namespace std;

int n, m;

void solve() {
	string s = "-";
	string tmp = s;
	for (int i = 0; i <= n; i++) {
		tmp = s;
		for (int j = 0; j < pow(3, i); j++) {
			s += " ";
		}
		s += tmp;
	}

	cout << tmp << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n) {
		solve();
	}
}