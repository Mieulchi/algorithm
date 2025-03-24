#include <iostream>
#include <string>
using namespace std;

int il, iu;
string l, u;
long long dp[11];
long long ans;

long long pow(int k) {
	long long res = 1;
	for (int i = 0; i < k; i++) {
		res *= 10;
	}
	return res;
}

void solve() {
	dp[1] = 45;
	for (int i = 2; i < 11; i++) {
		dp[i] = dp[i - 1] * 10 + 45 * pow(i - 1);
	}

	il -= il ? 1 : 0;
	u = to_string(iu);
	l = to_string(il);

	int len = u.length();
	int tmp = stoi(u);
	int op;
	for (int i = 0; i < len - 1; i++) {
		op = u[i] - '0';
		ans += op * dp[len - i - 1];
		if (op) {
			for (int j = 0; j < op; j++) {
				ans += j * pow(len - i - 1);
			}
		}
		ans += op * (tmp - op * pow(len - i - 1) + 1);
		tmp -= op * pow(len - i - 1);
	}
	op = u[len - 1] - '0';
	for (int i = 0; i <= op; i++) {
		ans += i;
	}

	len = l.length();
	tmp = stoi(l);
	for (int i = 0; i < len - 1; i++) {
		op = l[i] - '0';
		ans -= op * dp[len - i - 1];
		if (op) {
			for (int j = 0; j < op; j++) {
				ans -= j * pow(len - i - 1);
			}
		}
		ans -= op * (tmp - op * pow(len - i - 1) + 1);
		tmp -= op * pow(len - i - 1);
	}
	op = l[len - 1] - '0';
	for (int i = 0; i <= op; i++) {
		ans -= i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> il >> iu;
	solve();
	cout << ans;
}