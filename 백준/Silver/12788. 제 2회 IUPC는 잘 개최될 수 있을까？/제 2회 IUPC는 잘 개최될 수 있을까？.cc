#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m, k;
int arr[1001];
int ans;

void solve() {
	int need = m * k;
	sort(arr, arr + n);
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += arr[i];
		if (sum >= need) {
			ans = n - i;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;	
	cin >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve();
	if (!ans) {
		cout << "STRESS";
	}
	else {
		cout << ans;
	}
	
}