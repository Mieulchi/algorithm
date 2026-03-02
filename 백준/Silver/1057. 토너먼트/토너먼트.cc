#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int n, a, b;
int ans = 1;

void solve() {
	if (a > b) {
		swap(a, b);
	}
	while (!(abs(b - a) == 1 && a % 2)) {
		ans++;

		a += a % 2;
		a /= 2;

		b += b % 2;
		b /= 2;
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> a >> b;
	
	solve();

	cout << ans;
}