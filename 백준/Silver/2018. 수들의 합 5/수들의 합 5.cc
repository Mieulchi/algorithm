#include <iostream>
using namespace std;

int n;
int ans;

void solve() {
	int sum = 0;
	int i = 1;
	while (sum < n) {
		sum += i;
		if ((n - sum) % i == 0) {
			ans++;
		}
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}