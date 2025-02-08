#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001];
int ans = 1001000001;

void solve() {
	for (int i = 1; i <= 1000; i++) {
		if (arr[i]) {
			continue;
		}
		for (int j = i; j <= 1000; j++) {
			if (arr[j]) {
				continue;
			}
			for (int k = j; k <= 1001; k++) {
				if (arr[k]) {
					continue;
				}
				ans = min(ans, abs(n - i * j * k));
			}
		}
	}

	for (int i = 1; i <= 1000; i++) {
		if (arr[i] == 1)continue;
		for (int j = i; j <= 1000; j++) {
			if (arr[j] == 1)continue;
			for (int k = j; k <= 1001; k++) {
				if (arr[k] == 1)continue;
				ans = min(ans, abs(n - i * j * k));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}

	solve();

	cout << ans;
}
