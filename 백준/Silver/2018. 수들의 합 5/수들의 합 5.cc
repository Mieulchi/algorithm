#include <iostream>
using namespace std;

int n;
int ans;

void solve() {
	for (int i = 1; i < n; i++) {
		int sum = 0;
		int j = i;
		while (sum < n) {
			sum += j;
			j++;
			if (sum == n) {
				ans++;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ans = 1;
	solve();

	cout << ans;
}