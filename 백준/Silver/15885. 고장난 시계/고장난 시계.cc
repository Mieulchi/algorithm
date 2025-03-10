#include <iostream>
#include <algorithm>
using namespace std;

double a, b;
int ans;

void solve() {
	ans = (int)(abs(a / b - 1) * 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	solve();
	cout << ans;
}