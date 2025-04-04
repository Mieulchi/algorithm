#include <iostream>
using namespace std;

int n, k;
int arr[1000];
int ans;

void solve() {
	for (int i = 0; i < n; i++) {
		int cnt = n - 1;
		int flag = 1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (i > j) {
					if (arr[j] == arr[i] - (i - j) * k) {
						cnt--;
					}
					else {
						if (arr[i] - (i - j) * k <= 0) {
							flag = 0;
							break;
						}
					}
				}
				else {
					if (arr[j] == arr[i] + (j - i) * k) {
						cnt--;
					}
				}
			}
		}
		if ((!ans || ans > cnt) && flag) {
			ans = cnt;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}