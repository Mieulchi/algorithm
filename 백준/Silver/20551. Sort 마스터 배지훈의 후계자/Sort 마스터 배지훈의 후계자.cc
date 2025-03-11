#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[200000];
int ans;

void solve() {
	int key;
	cin >> key;
	if (binary_search(arr, arr + n, key)) {
		ans = lower_bound(arr, arr + n, key) - arr;
	}
	else {
		ans = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		solve();
		cout << ans << '\n';
	}
}