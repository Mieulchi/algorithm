#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
int arr[10000];
int arr2[9999];
int ans;

void solve() {
	for (int i = 0; i < n - 1; i++) {
		arr2[i] = arr[i + 1] - arr[i];
	}
	sort(arr2, arr2 + n - 1);

	int cnt = k - 1;
	int minus = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (cnt) {
			minus += arr2[i];
			cnt--;
		}
		else {
			break;
		}
	}
	ans = arr[n - 1] - arr[0] - minus;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	if (k < n) {
		solve();
	}

	cout << ans;
}