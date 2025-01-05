#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, m;
int list[50];
int volumes[50][1001];
int ans;

void check(int i) {
	for (int j = 0; j < 1000; j++) {
		if (volumes[i - 1][j]) {
			if (j + list[i] <= m) {
				volumes[i][j + list[i]] = 1;
			}
			if (j - list[i] >= 0) {
				volumes[i][j - list[i]] = 1;
			}
		}
	}
}

void solve() {
	if (s + list[0] <= m) {
		volumes[0][s + list[0]] = 1;
	}
	if (s - list[0] >= 0) {
		volumes[0][s - list[0]] = 1;
	}
	for (int i = 1; i < n; i++) {
		check(i);
	}
	for (int i = 1000; i >= 0; i--) {
		if (volumes[n - 1][i]) {
			ans = i;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s >> m;
	ans = -1;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	solve();

	cout << ans;
}