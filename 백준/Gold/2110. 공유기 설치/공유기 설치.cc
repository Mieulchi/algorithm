#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200000];
int myleft = 1000000001, myright;
int ans;

void solve() {
	int left = 1, right = myright - myleft;
	sort(arr, arr + n);
	while (left <= right) {
		int mid = (left + right) / 2;
		if ((myright - myleft) / mid < c - 1) {
			right = mid - 1;
		}
		else {
			int cnt = 1;
			int loc = 0;
			for (int i = 1; i < n; i++) {
				while (arr[i] - arr[loc] < mid && i < n) {
					i++;
				}
				if (i >= n) {
					break;
				}
				loc = i;
				cnt++;
			}
			if (cnt >= c) {
				if (mid > ans) {
					ans = mid;
				}
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < myleft) {
			myleft = arr[i];
		}
		if (arr[i] > myright) {
			myright = arr[i];
		}
	}
	if (c == 2) {
		ans = myright - myleft;
	}
	else {
		solve();
	}

	cout << ans;
}