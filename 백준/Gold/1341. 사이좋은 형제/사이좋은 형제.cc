#include <iostream>
using namespace std;

long long a, b;
long long c, d;
string ans;

void solve() {
	int i;
	long long mul = 2;
	for (i = 0; i < 60; i++) {
		if ((mul - 1) % b == 0) {
			long long div = (mul - 1) / b;
			b = (b - a) * div;
			a *= div;
			break;
		}
		mul *= 2;
	}
	if (i == 60) {
		ans = "-1";
	}
	else {
		mul /= 2;
		while (mul) {
			if (a >= mul) {
				a -= mul;
				ans += "*";
			}
			else {
				b -= mul;
				ans += "-";
			}
			mul /= 2;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	
	solve();

	cout << ans;
}