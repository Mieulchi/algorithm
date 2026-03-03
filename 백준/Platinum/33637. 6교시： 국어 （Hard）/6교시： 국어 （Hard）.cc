#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, t;
int arr[1001];
int S, M, E;
int s[401], m[401], e[401];
int ans;
int dp[401][401][401];
int nextTime[100005];
int bestTime[100005][1001];

void preprocess() {
	nextTime[t + 1] = INF;
	arr[n] = INF;

	int index = 0;
	for (int i = 0; i <= t; ++i) {
		if (i == arr[index]) {
			nextTime[i] = arr[index];
			++index;
		}
		else {
			nextTime[i] = arr[index];
		}
	}
	

	for (int i = 1; i < 1001; ++i) {
		bestTime[t + 1][i] = INF;

		for (int j = t; j >= 0; --j) {
			int start = (nextTime[j] == j) ? j + 1 : j;

			if (start + i <= t && start + i <= nextTime[start]) {
				bestTime[j][i] = start + i;
			}
			else {
				bestTime[j][i] = bestTime[j + 1][i];
			}   
		}
	}
}

void solve() {
	for (int i = 0; i < 401; ++i) {
		for (int j = 0; j < 401; ++j) {
			for (int k = 0; k < 401; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}

	preprocess();
	dp[0][0][0] = 0;
	
	for (int i = 0; i <= S; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k <= E; ++k) {
				if (dp[i][j][k] <= t) {
					if (i + 1 <= S) {
						int next = bestTime[dp[i][j][k]][s[i + 1]];
						if (next < dp[i + 1][j][k]) {
							dp[i + 1][j][k] = next;
							ans = max(ans, i + j + k + 1);
						}
					}

					if (j + 1 <= M) {
						int next = bestTime[dp[i][j][k]][m[j + 1]];
						if (next < dp[i][j + 1][k]) {
							dp[i][j + 1][k] = next;
							ans = max(ans, i + j + k + 1);
						}
					}

					if (k + 1 <= E) {
						int next = bestTime[dp[i][j][k]][e[k + 1]];
						if (next < dp[i][j][k + 1]) {
							dp[i][j][k + 1] = next;
							ans = max(ans, i + j + k + 1);
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> t;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> S >> M >> E;
	for (int i = 1; i <= S; ++i) {
		cin >> s[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> m[i];
	}
	for (int i = 1; i <= E; ++i) {
		cin >> e[i];
	}
	solve();
	cout << ans;
}