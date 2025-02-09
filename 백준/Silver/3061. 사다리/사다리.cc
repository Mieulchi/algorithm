#include <iostream>
#include <algorithm>
using namespace std;

int t, n, ans;
int arr[1001];

void solve() {
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i > 0; i--) {
		int idx = find(arr + 1, arr + n + 1, i) - arr;
		for (int j = idx; j < i; j++) {
			swap(arr[j], arr[j + 1]);
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		ans = 0;
		cin >> n;
		solve();
		cout << ans << '\n';
	}
}
