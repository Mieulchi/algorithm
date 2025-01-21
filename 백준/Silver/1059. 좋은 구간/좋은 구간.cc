#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[50];
int k;
int ans;


void solve() {
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] == k) {
			break;
		}
		if (arr[i] > k) {
			for (int j = arr[i - 1] + 1; j <= k; j++) {
				ans += (arr[i] - 1) - k + 1;
			}
			ans--;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	solve();

	cout << ans;
}