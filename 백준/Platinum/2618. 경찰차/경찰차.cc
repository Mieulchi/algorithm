#include <iostream>
#include <algorithm>
using namespace std;

int n, w;
pair<int, pair<int, int>> dp[2][1001][1001];
pair<int, int> arr[1001];
int ans;
string anss;

void solve() {
	cin >> arr[1].first >> arr[1].second;
	dp[0][1][0] = { abs(arr[1].first - 1) + abs(arr[1].second - 1), { 0, 0} };
	dp[1][1][0] = { abs(arr[1].first - n) + abs(arr[1].second - n), { 0, 0} };
	for (int i = 2; i <= w; i++) {
		cin >> arr[i].first >> arr[i].second;
		for (int j = 0; j < i - 1; j++) {
			if (dp[0][i - 1][j].first) {
				int dist = dp[0][i - 1][j].first + abs(arr[i - 1].first - arr[i].first) + abs(arr[i - 1].second - arr[i].second);
				if (!dp[0][i][j].first || dp[0][i][j].first > dist) {
					dp[0][i][j].first = dist;
					dp[0][i][j].second = { 0, j };
				}
				if (j == 0) {
					arr[0] = { n, n };
				}
				dist = dp[0][i - 1][j].first + abs(arr[j].first - arr[i].first) + abs(arr[j].second - arr[i].second);
				if (!dp[1][i][i - 1].first || dp[1][i][i - 1].first > dist) {
					dp[1][i][i - 1].first = dist;
					dp[1][i][i - 1].second = { 0, j };
				}
			}
			if (dp[1][i - 1][j].first) {
				int dist = dp[1][i - 1][j].first + abs(arr[i - 1].first - arr[i].first) + abs(arr[i - 1].second - arr[i].second);
				if (!dp[1][i][j].first || dp[1][i][j].first > dist) {
					dp[1][i][j].first = dist;
					dp[1][i][j].second = { 1, j };
				}
				if (j == 0) {
					arr[0] = { 1, 1 };
				}
				dist = dp[1][i - 1][j].first + abs(arr[j].first - arr[i].first) + abs(arr[j].second - arr[i].second);
				if (!dp[0][i][i - 1].first || dp[0][i][i - 1].first > dist) {
					dp[0][i][i - 1].first = dist;
					dp[0][i][i - 1].second = { 1, j  };
				}
			}
		}
	}
	ans = 1 << 31 - 1;
	int a, b, c;
	for (int i = 0; i < w; i++) {
		if (dp[0][w][i].first && ans > dp[0][w][i].first) {
			ans = dp[0][w][i].first;
			a = 0; b = w; c = i;
		}
		if (dp[1][w][i].first && ans > dp[1][w][i].first) {
			ans = dp[1][w][i].first;
			a = 1; b = w; c = i;
		}
	}

	for (int i = w; i > 0; i--) {
		anss += a + '1';

		int t1 = dp[a][i][c].second.first;
		int t2 = dp[a][i][c].second.second;
		a = t1;
		c = t2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w;
	solve();
	cout << ans << '\n';
	for (int i = anss.length() - 1; i >= 0; i--) {
		cout << anss[i] << '\n';
	}
}