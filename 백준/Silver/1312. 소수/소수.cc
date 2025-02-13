#include <iostream>
#include <algorithm>
using namespace std;

int a, b, n;
int ans;

void solve() {
	while (n--) {
		a %= b;
		a *= 10;
		ans = a / b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> n;
	
	solve();

	cout << ans;
}