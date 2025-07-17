#include <iostream>
using namespace std;

int n, s;
int sum[100000];
int arr[100000];
int ans;

bool f(int len) {
	for (int i = len - 1; i < n; i++) {
		if (sum[i] - sum[i - len] >= s) {
			return true;
		}
	}
	return false;
}

void solve() {
	int left = 1, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (f(mid)) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i) {
			sum[i] = sum[i - 1] + arr[i];
		}
		else {
			sum[0] = arr[0];
		}
	}
	solve();
	cout << ans;
}