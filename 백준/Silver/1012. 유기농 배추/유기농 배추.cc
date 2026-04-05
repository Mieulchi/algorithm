#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void erase(int** a, int r, int c, int w, int h) {
	a[r][c] = 0;
	if (c + 1 < w && a[r][c + 1] == 1) {
		erase(a, r, c + 1, w, h);
	}
	if (c - 1 >= 0 && a[r][c - 1] == 1) {
		erase(a, r, c - 1, w, h);
	}
	if (r + 1 < h && a[r + 1][c] == 1) {
		erase(a, r + 1, c, w, h);
	}
	if (r - 1 >= 0 && a[r - 1][c] == 1) {
		erase(a, r - 1, c, w, h);
	}
	return;
}

int main() {
	int k;
	cin >> k;

	int w, h, num;
	for (int i = 0; i < k; i++) {
		cin >> w >> h >> num;
		int** a = new int*[h];

		for (int i = 0; i < h; i++) {
			a[i] = new int[w];
			for (int j = 0; j < w; j++) {
				a[i][j] = 0;
			}
		}

		int x, y;
		for (int i = 0; i < num; i++) {
			cin >> x >> y;
			a[y][x] = 1;
		}

		int bugs = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j]) {
					erase(a, i, j, w, h);
					bugs++;
				}
			}
		}
		cout << bugs << '\n';
		delete[] a;
	}
}