#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

long long fib[90];
void solve() {
	for (int i = 3; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	fib[1] = 1;
	fib[2] = 1;
	if (n > 2) {
		solve();
	}

	cout << fib[n];
}