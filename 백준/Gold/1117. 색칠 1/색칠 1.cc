#include <iostream>
#include <algorithm>
using namespace std;

long long w, h, f, c, X1, Y1, X2, Y2;
long long ans;

void solve() {
	
	long long cpy = 0, cnt = 0;
	if (f != w && f != 0) {
		long long origin = (c + 1) * (Y2 - Y1);

		cnt = origin * (min(X2, w - f) - min(X1, w - f));

		cpy = origin * (max(0LL, f - X1) - max(0LL, f - X2));
	}
	else {
		cnt = (X2 - X1) * (Y2 - Y1);
		cnt *= (c + 1);
	}

	ans = (w * h) - (cnt + cpy);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> w >> h >> f >> c >> X1 >> Y1 >> X2 >> Y2;

	solve();

	cout << ans;
 }
