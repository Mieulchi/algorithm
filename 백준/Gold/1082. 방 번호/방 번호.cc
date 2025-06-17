#include <iostream>
using namespace std;

int n;
int arr[10];
int m;
int minPrice = 51;
int minum;
string ans;

void solve() {
	for (int i = 0; i < m / minPrice; i++) {
		ans += minum + '0';
	}
	m -= (m / minPrice) * minPrice;

	if (ans == "") {
		ans = "0";
	}
	int idx = 0;
	while ((ans[0] == '0' || m) && idx < ans.length()) {
		int flag = 0;
		for (int i = n - 1; i > 0; i--) {
			if (arr[i] - minPrice <= m) {
				flag = 1;
				ans[idx] = i + '0';
				m -= arr[i] - minPrice;
				idx++;
				break;
			}
		}
		if (flag) {
			continue;
		}
		if (ans[0] == '0' && ans.length() > 1) {
			string tmp;
			for (int i = 1; i < ans.length(); i++) {
				tmp += ans[i];
			}
			ans = tmp;
			m += minPrice;
			continue;
		}
		break;
	}
	if (ans.length() > 1 && ans[0] == '0') {
		ans = "0";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= minPrice) {
			minPrice = arr[i];
			minum = i;
		}
	}
	cin >> m;
	solve();
	cout << ans;
}