#include <iostream>
using namespace std;

int cheese[101][101];
int tmp[101][101];
int cheesecount = 0;

void checkout(int r, int c, int tmpr, int tmpc) {
	cheese[tmpr][tmpc] = -1;
	if (tmpr + 1 < r && cheese[tmpr + 1][tmpc] == 0) {
		checkout(r, c, tmpr + 1, tmpc);
	}
	if (tmpr - 1 >= 0 && cheese[tmpr - 1][tmpc] == 0) {
		checkout(r, c, tmpr - 1, tmpc);
	}
	if (tmpc + 1 < c && cheese[tmpr][tmpc + 1] == 0) {
		checkout(r, c, tmpr, tmpc + 1);
	}
	if (tmpc - 1 >= 0 && cheese[tmpr][tmpc - 1] == 0) {
		checkout(r, c, tmpr, tmpc - 1);
	}
}


void melt(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cheese[i][j] == 1) {
				int count = 0;
				if (i + 1 < r) {
					if (cheese[i + 1][j] == -1) {
						count++;
					}
				}
				if (i - 1 >= 0) {
					if (cheese[i - 1][j] == -1) {
						count++;
					}
				}
				if (j + 1 < c) {
					if (cheese[i][j + 1] == -1) {
						count++;
					}
				}
				if (j - 1 >= 0) {
					if (cheese[i][j - 1] == -1) {
						count++;
					}
				}

				if (count >= 2) {
					cheesecount--;
					cheese[i][j] = -2;
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cheese[i][j] == -2) { 
				cheese[i][j] = -1;
				checkout(r, c, i, j);
			}
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) {
				cheesecount++;
			}

		}
	}
	int hour = 0;
	checkout(n, m, 0, 0);

	while (cheesecount > 0) {
		melt(n, m);
		hour++;
	}



	cout << hour;
}