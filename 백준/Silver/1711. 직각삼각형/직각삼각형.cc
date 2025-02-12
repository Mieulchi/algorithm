#include <iostream>
using namespace std;

int n;
int x[1500];
int y[1500];
int ans;

bool check(int i, int j, int k) {
	pair<long long, long long> v1 = { x[i] - x[j], y[i] - y[j] };
	pair<long long, long long> v2 = { x[j] - x[k], y[j] - y[k] };
	pair<long long, long long> v3 = { x[k] - x[i], y[k] - y[i] };
	if (v1.first * v2.first + v1.second * v2.second == 0 || v2.first * v3.first + v2.second * v3.second == 0 || v3.first * v1.first + v3.second * v1.second == 0) {
		return true;
	}
	return false;
}

void solve() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (check(i, j, k)) {
					ans++;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	solve();

	cout << ans;
}