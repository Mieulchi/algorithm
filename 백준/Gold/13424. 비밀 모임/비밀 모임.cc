#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int t;
int n, m, k;
int graph[101][101];
int arr[101];
int ans;

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			graph[i][j] = INF;
			if (i == j) {
				graph[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		arr[i] = 0;
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				graph[j][k] = min(graph[j][k], graph[i][j] + graph[i][k]);
			}
		}
	}

	int min = INF;

	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (arr[j]) {
				sum += graph[i][j];
			}
		}
		if (sum < min) {
			min = sum;
			ans = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a][b] = c;
			graph[b][a] = c;
		}

		
		cin >> k;
		for (int i = 0; i < k; ++i) {
			int t;
			cin >> t;
			arr[t] = 1;
		}
		solve();

		cout << ans << '\n';
	}
}