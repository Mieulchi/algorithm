#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];
int ans;

void solve() {
	sort(arr, arr + n);
	int j = 0;
	ans = 2000000000;
	for (int i = 0; i < n; i++) {		
		while (j < n && arr[j] - arr[i] < m) {
			j++;

		}
		if (j == n) {
			break;
		}
		ans = min(ans, arr[j] - arr[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}