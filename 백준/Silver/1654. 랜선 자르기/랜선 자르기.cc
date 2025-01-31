#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
long long arr[10001];
int ans;

void solve() {
	long long left = 1, right = arr[k - 1];
	while (true) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if (mid > ans) {
				ans = mid;
			}
			if (left > right) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + k);
	solve();

	cout << ans;
}