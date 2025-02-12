#include <iostream>
using namespace std;

int n, d;
int from[12];
int to[12];
int dist[12];
int dp[10001];
int ans;

void findShortCut(int i) {
	for (int j = 0; j < n; j++) {
		if (from[j] == i) {
			if (dp[to[j]] == 0 || dp[to[j]] > dp[i] + dist[j]) {
				dp[to[j]] = dp[i] + dist[j];
			}
		}
	}
}

void solve() {
	for (int i = 0; i <= d; i++) {
		if (i != 0 && (dp[i] == 0 || dp[i - 1] + 1 < dp[i]) ) {
			dp[i] = dp[i - 1] + 1;
		}
		findShortCut(i);
	}
	ans = dp[d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> from[i] >> to[i] >> dist[i];
	}

	solve();

	cout << ans;
}