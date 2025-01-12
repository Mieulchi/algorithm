#include <iostream>
#include <map>
using namespace std;

int t;
int n;
int arr[300];
int ans;
map<int, int> m;

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ans = 1;

	while (true) {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (m[arr[i] % ans]) {
				flag = 0;
				break;
			}
			else {
				m[arr[i] % ans] = 1;
			}
		}
		if (flag) {
			m.clear();
			break;
		}
		m.clear();
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		solve();

		cout << ans << '\n';
	}
}