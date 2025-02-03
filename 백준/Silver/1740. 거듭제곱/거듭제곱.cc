#include <iostream>
using namespace std;

long long n;
long long ans;

long long square(int k) {
	long long res = 1;
	for (int i = 0; i < k; i++) {
		res *= 3;
	}
	return res;
}

void solve() {
	for (int i = 0; i <= 60; i++) {
		if ((n >> i) & 1) {
			ans += square(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; 

	solve();

	cout << ans;
}