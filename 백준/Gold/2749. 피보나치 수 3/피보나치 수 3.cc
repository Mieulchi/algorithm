#include <iostream>
#include <climits>
#include <map>
using namespace std;

map<long long, long long> dp;

int fib(long long n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}

	if (n % 2 == 1) {
		n++;
		long long op1, op2;
		if (dp[n / 2]) {
			op1 = dp[n / 2];
		}
		else {
			op1 = fib(n / 2);
			dp[n / 2] = op1;
		}

		if (dp[n / 2 - 1]) {
			op2 = dp[n / 2 - 1];
		}
		else {
			op2 = fib(n / 2 - 1);
			dp[n / 2 - 1] = op2;
		}
\
		long long result = op1 * op1 + op2 * op2;
		if (result > 1000000) {
			result %= 1000000;
		}
		return result;
	}
	else {
		long long op1, op2;

		if (dp[n / 2 - 1]) {
			op1 = dp[n / 2 - 1];
		}
		else {
			op1 = fib(n / 2 - 1);
			dp[n / 2 - 1] = op1;
		}

		if (dp[n / 2]) {
			op2 = dp[n / 2];
		}
		else {
			op2 = fib(n / 2);
			dp[n / 2] = op2;
		}

		long long result = (2 * op1 + op2) * op2;
		if (result > 1000000) {
			result %= 1000000;
		}
		return result;
	}
}

int main() {
	long long n;
	cin >> n;

	long long op1 = 0;
	long long op2 = 1;

    int result = fib(n);

	cout << result % 1000000;
}