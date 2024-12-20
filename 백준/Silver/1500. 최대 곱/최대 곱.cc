#include <iostream>
#include <climits>
using namespace std;

int s, k;

long long ans;

void solve() {
	ans = 1;
	while (s) {
		int op = s / k;
		if (s % k) {
			op++;
		}

		ans *= op;
		s -= op;
		k--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> k;

	solve();

	cout << ans;
}