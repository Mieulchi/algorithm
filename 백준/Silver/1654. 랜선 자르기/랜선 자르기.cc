#include <stdio.h>
using namespace std;

int k, n;
long long arr[10001];
int ans;
int mymax;

void solve() {
	long long left = 1, right = mymax;
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
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &arr[i]);
		if (arr[i] > mymax) {
			mymax = arr[i];
		}
	}
	solve();

	printf("%d", ans);
}