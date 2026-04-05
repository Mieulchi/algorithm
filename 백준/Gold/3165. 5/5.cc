#include <iostream>
using namespace std;

long long n;
int k;
long long ans;

int count(long long tmp) {
	int cnt = 0;
	while (tmp) {
		if (tmp % 10 == 5) {
			cnt++;
		}
		tmp /= 10;
	}
	return cnt;
}

void solve() {
	n++;
	long long div = 10;
	while (true) {
		count(n);
		int cnt = count(n);
		
		if (cnt >= k) {
			break;
		}
		if (n % div / (div / 10) >= 5) {
			n -= (n % div - (n % div) % (div / 10));
			n += div;
			cnt = count(n);
			if (cnt < k) {
				n += 5 * (div / 10);
			}
		}
		else {
			n -= (n % div - (n % div) % (div / 10));
			n += 5 * (div / 10);
		}
		div *= 10;
	}
	ans = n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << ans;
}