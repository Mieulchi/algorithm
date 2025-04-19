#include <iostream>
#include <algorithm>
using namespace std;

int t;
int p, q, a, b, c, d;
int ans;

void solve() {
	int bit = p;
	int coin = (q / c) * d;
	
	bit += (coin / b) * a;
	coin %= b;
	
	int x = bit / (a + b);
	ans = min(bit - a * x, coin + b * x);
	if (bit - a * (x + 1) > 0) {
		ans = max(ans, min(bit - a * (x + 1), coin + b * (x + 1)));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> p >> q >> a >> b >> c >> d;
		solve();
		cout << ans << '\n';
	}
}