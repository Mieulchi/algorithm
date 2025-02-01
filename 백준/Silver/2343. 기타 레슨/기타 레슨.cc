#include <iostream>
using namespace std;

int n, m;
int arr[100000];
int sum;
int ans;

void solve() {
	int left = arr[0], right = sum;
	ans = sum;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		int tmp = 0;
		int flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > mid) {
				flag = 1;
				break;
			}
			tmp += arr[i];
			if (i == n - 2) {
				if (tmp + arr[n - 1] <= mid) {
					cnt++;
				}
				else {
					cnt += 2;
				}
				break;
			}
			if (tmp + arr[i + 1] > mid) {
				cnt++;
				tmp = 0;
			}

		}
		if (flag) {
			left = mid + 1;
			continue;
		}
		if (cnt > m) {
			left = mid + 1;
		}
		else {
			if (ans > mid) {
				ans = mid;
			}
			right = mid - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	solve();

	cout << ans;
}