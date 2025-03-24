#include <iostream>
#include <string>
using namespace std;

int il, iu;
long long dp[11];
long long ans;

long long pow(int k) {
	long long res = 1;
	for (int i = 0; i < k; i++) {
		res *= 10;
	}
	return res;
}

long long getSum(string s) {
	int len = s.length();
	int tmp = stoi(s);
	int op;
	long long sum = 0;
	for (int i = 0; i < len - 1; i++) {
		op = s[i] - '0';
		sum += op * dp[len - i - 1];
		if (op) {
			for (int j = 0; j < op; j++) {
				sum += j * pow(len - i - 1);
			}
		}
		sum += op * (tmp - op * pow(len - i - 1) + 1);
		tmp -= op * pow(len - i - 1);
	}
	op = s[len - 1] - '0';
	for (int i = 0; i <= op; i++) {
		sum += i;
	}
	return sum;
}

void solve() {
	dp[1] = 45;
	for (int i = 2; i < 11; i++) {
		dp[i] = dp[i - 1] * 10 + 45 * pow(i - 1);
	}

	il -= il ? 1 : 0;

	ans += getSum(to_string(iu));
	ans -= getSum(to_string(il));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> il >> iu;
	solve();
	cout << ans;
}