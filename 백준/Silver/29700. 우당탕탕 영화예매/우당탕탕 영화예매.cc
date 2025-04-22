#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int ans;

void solve() {
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				cnt = 0;
			}
			else {
				cnt++;
				if (cnt >= k) {
					ans++;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n >> m >> k;
	solve();
	cout << ans;
}