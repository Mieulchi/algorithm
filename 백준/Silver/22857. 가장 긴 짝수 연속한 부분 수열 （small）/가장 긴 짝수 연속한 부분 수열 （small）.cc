#include <iostream>
using namespace std;

int n, k;
int even[50001];
int arr[50001];
int ans;

int check(int mid) {
	int flag = 0;
	for (int i = 0; i <= n - mid; i++) {
		int op = even[i + mid - 1] - (i ? even[i - 1] : 0);
		if (op >= mid - k) {
			if (op > ans) {
				ans = op;
			}
			flag = 1;
		}
	}
	return flag ? 1 : 0;
}

void solve() {
	int left = 1, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;

		int flag = check(mid);
		if (flag) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0) {
			even[i] = even[i - 1];
		}
		if (arr[i] % 2 == 0) {
			even[i]++;
		}
	}
	solve();
	cout << ans;
}