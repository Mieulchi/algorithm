#include <iostream>
#include <algorithm>
using namespace std;

#define INF -1

int n;
long long ans;
int arr[200000];
long long sum[200000];

void solve() {
	long long find = sum[n - 1] / 2;
	if (sum[n - 1] % 2) { ++find; }
	int idx = lower_bound(sum, sum + n, find) - sum;

	if (sum[idx] == find) {
		for (int i = 0; i <= idx; ++i) {
			if (arr[i]) {
				ans += (2LL * i * arr[i]);
			}
		}
		if (sum[n - 1] % 2) {
			ans -= idx;
		}
		idx = lower_bound(sum, sum + n, find + 1) - sum;

		for (int i = idx; i < n; ++i) {
			if (arr[i]) {
				ans += 2LL * (n - i) * arr[i];
			}
		}

		if (sum[n - 1] % 2 == 0) {
			ans -= (n - idx);
		}
	}
	else {
		for (int i = 0; i < idx; ++i) {
			if (arr[i]) {
				ans += 2 * i * arr[i];
			}
		}
		ans += 2LL * idx * (find - sum[idx - 1]);
		if (sum[n - 1] % 2) {
			ans -= idx;
		}

		for (int i = idx + 1; i < n; ++i) {
			if (arr[i]) {
				ans += 2LL * (n - i) * arr[i];
			}
		}

		ans += 2LL * (sum[idx] - find) * (n - idx);

		if (sum[n - 1] % 2 == 0) {
			ans -= (n - idx);
		}
	}



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum[i] = arr[i];
		if (i) {
			sum[i] += sum[i - 1];
		}
	}
	solve();

	cout << ans;

}