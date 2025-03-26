#include <iostream>
using namespace std;

int t;
int n, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> c;
		int ans = n / c;
		ans += n % c ? 1 : 0;
		cout << ans << '\n';
	}
}