#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9

typedef long long ll;

/*
	
	완탐
	10! * 10
*/
int n, k;
int arr[10][10];
int ans = INF;

void dfs(int bitmask, int depth, int sum, int prev) {
	if (depth != n) {
		for (int i = 0; i < n; ++i) {
			if (((bitmask >> i) & 1) == 0) {

				dfs(bitmask | (1 << i), depth + 1, sum + arr[prev][i], i);
			}
		}
	}
	else {
		ans = min(ans, sum);
	}
}

void solve() {
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i != k) {
			dfs((1 << k) | (1 << i), 2, arr[k][i], i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	solve();

	cout << ans;
}