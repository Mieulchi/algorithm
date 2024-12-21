#include <iostream>
#include <climits>
using namespace std;

int a, b, c;
long long ans;

void solve() {
	ans = 1;
	long long op = a % c;
	while (b) {
		if (b % 2) {
			ans = (ans * op) % c;
		}
		op = (op * op) % c;
		b /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;

	solve();

	cout << ans;
}