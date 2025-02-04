#include <iostream>
using namespace std;

int n, k;
int l[100000];
int ans;

void solve() {
	for (int i = 1; i < n; i++) {
		int cnt = 1;
		int used = 0;
		if (n - ans >= i) {
			for (int j = i; j < n; j++) {
				if (l[j] <= k) {
					cnt++;
				}
				else {
					if (!used) {
						cnt++;
						used = 1;
					}
					else {
						break;
					}
				}
			}
			if (cnt > ans) {
				ans = cnt;
			}
		}
	}
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> l[i];
	}

	solve();

	cout << ans;
}