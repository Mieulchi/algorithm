#include <iostream>
#include <vector>
using namespace std;

int a, b, x, ans;
vector<int> v[201];

int check(int n, int x, int y) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (n % (x * i + y * j) == 0) {
				return 1;
			}
		}
	}
	return 0;
}

void solve() {
	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j * j == i) {
				v[i].push_back(j);
			}
			else if(i % j == 0) {
				v[i].push_back(j);
				v[i].push_back(i / j);
			}
		}
	}

	if (a % x == 0 && b % x == 0) {
		ans = -1;
	}
	else {
		ans = 1;
		for (int i = 2; i <= 200; i++) {
			if ((a % x == 0 || a % i == 0 || check(a, x, i)) && (b % x == 0 || b % i == 0 || check(b, x, i))) {
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> x;
	solve();
	cout << ans;
}