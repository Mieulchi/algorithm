#include <iostream>
#include <vector>
using namespace std;

int area[101];
int graph[101][101];


void floid(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (graph[j][i] && graph[i][k] && j != k) {
					if (graph[j][k] == 0) {
						graph[j][k] = graph[j][i] + graph[i][k];
					}
					else {
						if (graph[j][k] > graph[j][i] + graph[i][k]) {
							graph[j][k] = graph[j][i] + graph[i][k];
						}
					}
				}
			}
		}
	}
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		cin >> area[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = c;
		graph[b - 1][a - 1] = c;
	}

	floid(n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((graph[i][j] > 0 || i == j) && graph[i][j] <= m) {
				sum += area[j];
			}
		}
		if (max < sum) {
			max = sum;
		}
	}

	cout << max;
}