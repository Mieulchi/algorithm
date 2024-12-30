#include <iostream>
using namespace std;

long long m, n, ans;

long long getGcd(long long a, long long b) {
	if (a < b) {
		long long swp = b;
		b = a;
		a = swp;
	}
	while (b) {
		long long tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

long long getLcm(long long a, long long b) {
	long long gcd = getGcd(a, b);

	return gcd * (a / gcd) * (b / gcd);
}

void solve() {
	int i = n / m;
	while (true) {
		long long lcm = getLcm(n, i);
		if (m * (lcm / n) >= lcm / i) {
			long long tmpm = m * (lcm / n) - lcm / i;
			long long tmpn = lcm;
			long long tmp = getGcd(tmpm, tmpn);
			tmpm /= tmp;
			tmpn /= tmp;
			if (tmpn >= 1000000) {
				i++;
				continue;
			}
			m = tmpm;
			n = tmpn;
			
			cout << i << ' ';
			if (m == 0) {
				break;
			}
			i = n / m;
		}
		else {
			i++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}

		solve();
		cout << '\n';
	}
}