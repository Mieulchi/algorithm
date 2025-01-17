#include <iostream>
using namespace std;

int n;
int stairs[300];
int result[300][2];
int ans;

void solve() {
	result[0][0] = stairs[0];
	result[1][0] = stairs[1];
	result[1][1] = result[0][0] + stairs[1];
	for (int i = 2; i < n; i++) {
		if (result[i - 2][0] > result[i - 2][1]) {
			result[i][0] = result[i - 2][0] + stairs[i];
		}
		else {
			result[i][0] = result[i - 2][1] + stairs[i];
		}

		result[i][1] = result[i - 1][0] + stairs[i];
	}
	if (result[n - 1][0] > result[n - 1][1]) {
		ans = result[n - 1][0];
	}
	else {
		ans = result[n - 1][1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	solve();

	cout << ans;
}