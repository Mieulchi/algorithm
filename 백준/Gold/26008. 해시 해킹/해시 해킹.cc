#include <iostream>
using namespace std;
#define MOD 1000000007

int n, m, a, h;
long long ans;

void solve() {
	ans = 1;
	n--;
	long long base = m;
	while (n) {
		if (n & 1) { 
			ans = (ans * base) % MOD;
		}
		base = (base * base) % MOD;
		n /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a;
	cin >> h;
	solve();
	cout << ans;
}