#include <iostream>
using namespace std;

int t;
int n;

long long fib[41][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	fib[0][0] = 1;
	fib[0][1] = 0;
	fib[1][0] = 0;
	fib[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		fib[i][0] = fib[i - 2][0] + fib[i - 1][0];
		fib[i][1] = fib[i - 2][1] + fib[i - 1][1];
	}

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fib[n][0] << ' ' << fib[n][1] << '\n';
	}
}