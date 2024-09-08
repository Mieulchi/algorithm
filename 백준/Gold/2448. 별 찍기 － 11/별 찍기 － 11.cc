#include <iostream>
#include <cmath>
using namespace std;

char paint[3073][6144];

void recursive(int r, int c, int level) {
	if (level == 0) {
		paint[r][c] = '*';
		paint[r + 1][c+1] = '*';
		paint[r + 1][c - 1] = '*';
		for (int i = -2; i <= 2; i++) {
			paint[r + 2][c + i] = '*';
		}
		return;
	}
	else {
		int col = (5 * pow(2, level - 1) + pow(2, level - 1) - 1) / 2;
		recursive(r, c, level - 1);
		recursive(r + 3 * pow(2, level - 1), c - col - 1, level - 1);
		recursive(r + 3 * pow(2, level - 1), c + col + 1, level - 1);
	}
}

int main() {
	int n;
	cin >> n;

	int k = n / 3;
	int count = 0;
	int copy = k;
	while (copy != 1) {
		copy /= 2;
		count++;
	}

	int col = 5 * k + k - 1;

	//23
	recursive(0, col / 2, count);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < col; j++) {
			if (paint[i][j] != '*') {
				cout << ' ';
			}
			else {
				cout << paint[i][j];
			}
		}
		cout << '\n';
	}
}