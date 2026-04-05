#include <iostream>
using namespace std;

int origin[51][51];
int cpy[51][51];

void resetcpy(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cpy[i][j] = 0;
		}
	}
}

void simulate(int r, int c, int air1, int air2) {
	//spread 
	resetcpy(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (origin[i][j] > 0) {
				int count = 0;
				int op = origin[i][j] / 5;
				if (i + 1 < r && origin[i + 1][j] != -1) {
					count++;
					cpy[i + 1][j] += op;
				}
				if (i - 1 >= 0 && origin[i - 1][j] != -1) {
					count++;
					cpy[i - 1][j] += op;
				}
				if (j + 1 < c && origin[i][j + 1] != -1) {
					count++;
					cpy[i][j + 1] += op;
				}
				if (j - 1 >= 0 && origin[i][j - 1] != -1) {
					count++;
					cpy[i][j - 1] += op;
				}
				cpy[i][j] += op * count * -1;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			origin[i][j] += cpy[i][j];
		}
	}

	//wind
	// upper	
	origin[air1 - 1][0] = 0;
	for (int i = air1 - 1; i > 0; i--) {
		origin[i][0] = origin[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		origin[0][i] = origin[0][i + 1];
	}
	for (int i = 0; i < air1; i++) {
		origin[i][c - 1] = origin[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		origin[air1][i] = origin[air1][i - 1];
	}
	origin[air1][1] = 0;

	// lower
	origin[air2 +1][0] = 0;
	for (int i = air2 + 1; i < r - 1; i++) {
		origin[i][0] = origin[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		origin[r - 1][i] = origin[r - 1][i + 1];
	}
	for (int i = r - 1; i > air2 ; i--) {
		origin[i][c - 1] = origin[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		origin[air2][i] = origin[air2][i - 1];
	}
	origin[air2][1] = 0;
}

int getMeonji(int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (origin[i][j] > 0) {
				sum += origin[i][j];
			}
		}
	}

	return sum;
}

int main() {
	int r, c, t;
	int aircon[2] = { -1, -1 };

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> origin[i][j];
			if (origin[i][j] == -1) {
				if (aircon[0] == -1) {
					aircon[0] = i;
				}
				else {
					aircon[1] = i;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		simulate(r, c, aircon[0], aircon[1]);
	}

	int result = getMeonji(r, c);

	cout << result;
}