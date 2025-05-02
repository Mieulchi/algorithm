#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
pair<int, int> arr[10];
long long ans = LLONG_MAX;

void solve() {
	int k = 1 << n;
	for (int i = 1; i < k; i++) {
		long long sin = 0;
		long long sseun = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				if (!sin) {
					sin = 1;
				}
				sin *= arr[j].first;
				sseun += arr[j].second;
			}
		}
		if (abs(sin - sseun) < ans) {
			ans = abs(sin - sseun);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	solve();
	cout << ans;
}