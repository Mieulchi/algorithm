#include <iostream>

using namespace std;

int lab[9][9];
int tmp[9][9];

int maxcount= 0;

void init_tmp(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = lab[i][j];
		}
	}
}

void infect(int i, int j, int n, int m) {
	tmp[i][j] = 2;
	if (i + 1 < n && tmp[i + 1][j] == 0) {
		infect(i + 1, j, n, m);
	}
	if (i - 1 >= 0 && tmp[i - 1][j] == 0) {
		infect(i - 1, j, n, m);
	}
	if (j + 1 < m && tmp[i][j + 1] == 0) {
		infect(i, j + 1, n, m);
	}
	if (j - 1 >= 0 && tmp[i][j - 1] == 0) {
		infect(i, j - 1, n, m);
	}
}

void bfs(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2) {
				infect(i, j, n, m);
			}
		}
	}
}

int getCount(int n, int m) {
	bfs(n, m);
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				count++;
			}
		}
	}

	return count;
}

void search(int n, int m) {
	init_tmp(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j]== 0) {
				tmp[i][j] = 1;
				for (int i1 = i; i1 < n; i1++) {
					for (int j1 = 0; j1 < m; j1++) {
						if (tmp[i1][j1] == 0) {
							if (i1 == i && j1 <= j) {
								continue;
							}
							tmp[i1][j1] = 1;
							for (int i2 = i1; i2 < n; i2++) {
								for (int j2 = 0; j2 < m; j2++) {
									if (tmp[i2][j2] == 0) {
										if (i2 == i1 && j2 <= j1) {
											continue;
										}
										tmp[i2][j2] = 1;
										int cmp = getCount(n, m);
										if (cmp >= maxcount) {
											maxcount = cmp;

										}
										init_tmp(n, m);
										tmp[i][j] = 1;
										tmp[i1][j1] = 1;
									}
								}
							}
							init_tmp(n, m);
							tmp[i][j] = 1;
						}
					}
				}
				init_tmp(n, m);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}

	search(n, m);

	cout << maxcount;
}