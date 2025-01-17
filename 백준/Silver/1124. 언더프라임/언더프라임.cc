#include <iostream>
using namespace std;

int a, b;
int prime[100001];
int ans;

void solve() {
	for (int i = a; i <= b; i++) {
		int j = i;
		int count = 0;
		while (j > 1) {
			j /= prime[j];
			count++;
		}
		if (prime[count] == count) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	for (int i = 2; i <= 100000; i++) {
		for (int j = i; j <= 100000; j += i) {
			if (prime[j]) {
				continue;
			}
			prime[j] = i;
		}
	}

	solve();

	cout << ans;
}