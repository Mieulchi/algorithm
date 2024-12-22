#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
long long ans;

int arr[1000];

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	ans = 1;
	int x = arr[0] + l - 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= x) {
			continue;
		}
		else {
			ans++;
			x = arr[i] + l - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;

	solve();

	cout << ans;
}