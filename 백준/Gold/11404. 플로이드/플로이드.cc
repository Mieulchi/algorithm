#include <iostream>
using namespace std;

int graph[101][101];

void fluid(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (graph[j][i]  && graph[i][k]) {
					if (graph[j][k] == 0) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
					else if (graph[j][k] > graph[j][i] + graph[i][k]) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (!graph[a - 1][b - 1]) {
			graph[a - 1][b - 1] = c;
		}
		else {
			if (graph[a - 1][b - 1] > c) {
				graph[a - 1][b - 1] = c;
			}
		}
	}

	fluid(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] <<' ';
		}
		cout << '\n';
	}
}