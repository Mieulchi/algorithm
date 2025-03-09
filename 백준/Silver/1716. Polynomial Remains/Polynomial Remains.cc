#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int arr[10001];
int res[10001];

void solve() {
	for (int i = 0; i <= n; i++) {
		cin >> arr[i];
	}
	if (k == 0) {
		cout << 0 << '\n';
		return;
	}
	for (int i = n; i >= 0; i--) {
		if (i < k) {
			break;
		}
		int coef = arr[i];
		arr[i] -= coef;
		arr[i - k] -= coef;
	}
	int flag = 1;
	for (int i = 0; i <= n; i++) {
		if (arr[i]) {
			flag = 0;
			cout << arr[i] << ' ';
		}
	}
	if (flag) {
		cout << 0;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true) {
		cin >> n >> k;
		if (n == -1 && k == -1) {
			break;
		}
		solve();
	}
}