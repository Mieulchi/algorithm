#include <iostream>
using namespace std;

#define INF 1000000007

int n, m, q;

int dist[101][101][101];

void floyd(int ex) {
	for (int node = 1; node <= n; ++node) {
		if (node == ex) {
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (i == node || i == ex) {
				continue;
			}
			for (int j = 1; j <= n; ++j) {
				if (j == node || j == ex || i == j) {
					continue;
				}
				if (dist[i][ex][j] > dist[i][ex][node] + dist[node][ex][j]) {
					dist[i][ex][j] = dist[i][ex][node] + dist[node][ex][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dist[i][j][k] = INF;
				
			}
		}
	}

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;

		for (int j = 1; j <= n; ++j) {
			dist[a][j][b] = c;
		}
	}


	for (int ex = 1; ex <= n; ++ex) {
		floyd(ex);
	}


	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> c;

		if (dist[a][b][c] != INF) {
			cout << dist[a][b][c];
		}
		else {
			cout << "No";
		}
		cout << '\n';


	}
}