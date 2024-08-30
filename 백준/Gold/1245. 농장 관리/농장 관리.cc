#include <iostream>
#include <cmath>
using namespace std;

int farm[101][71];
int check[101][71];
int checktmp[101][71];

void countcheck(int n, int m, int r, int c) {
	check[r][c] = 0;

	if (c + 1 < m) {
		if (check[r][c + 1]) {
			countcheck(n, m, r, c + 1);
		}
		if (r + 1 < n) {
			if (check[r +1][c + 1]) {
				countcheck(n, m, r + 1, c + 1);
			}
		}
		if (r - 1 >= 0) {
			if (check[r - 1][c + 1]) {
				countcheck(n, m, r - 1, c + 1);
			}
		}
	}
	if (c - 1 >= 0) {

		if (check[r][c - 1]) {
			countcheck(n, m, r, c - 1);
		}
		if (r + 1 < n) {
			if (check[r + 1][c - 1]) {
				countcheck(n, m, r + 1, c - 1);
			}
		}
		if (r - 1 >= 0) {
			if (check[r - 1][c - 1]) {
				countcheck(n, m, r - 1, c - 1);
			}
		}
	}
	if (r + 1 < n) {
		if (check[r + 1][c]) {
			countcheck(n, m, r + 1, c);
		}
	}
	if (r - 1 >= 0) {
		if (check[r - 1][c]) {
			countcheck(n, m, r - 1, c);
		}
	}
}

void clearcheck(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			checktmp[i][j] = 0;
		}
	}
}

bool distinguishiDfs(int n, int m, int r, int c) {
	bool result = true;
	checktmp[r][c] = 1;
	if (r < 0 || r > n || c < 0 || c > m) {
	}
	else {
		if (c + 1 < m) {
			if (farm[r][c + 1] == farm[r][c]) {
				if (farm[r][c + 1] != 0 && checktmp[r][c + 1] == 0) {
					if (!distinguishiDfs(n, m, r, c + 1)) {
						return false;
					}
				}
			}
			else if (farm[r][c+1] > farm[r][c]) {
				return false;
			}
			if (r + 1 < n) {
				if (farm[r + 1][c + 1] == farm[r][c]) {
					if (farm[r + 1][c + 1] != 0 && checktmp[r + 1][c + 1] == 0) {
						if (!distinguishiDfs(n, m, r + 1, c + 1)) {
							return false;
						}
					}
				}
				else if (farm[r + 1][c + 1] > farm[r][c]) {
					return false;
				}
			}
			if (r - 1 >= 0) {
				if (farm[r - 1][c + 1] == farm[r][c]) {
					if (farm[r - 1][c + 1] != 0 && checktmp[r - 1][c + 1] == 0) {
						if (!distinguishiDfs(n, m, r - 1, c + 1)) {
							return false;
						}
					}
				}
				else if (farm[r - 1][c + 1] > farm[r][c]) {
					return false;
				}
			}
		}
		if (c - 1 >= 0) {
			if (farm[r][c - 1] == farm[r][c] ) {
				if (farm[r][c - 1] != 0 && checktmp[r][c - 1] == 0) {
					if (!distinguishiDfs(n, m, r, c - 1)) {
						return false;
					}
				}
			}
			else if (farm[r][c - 1] > farm[r][c]) {
				return false;
			}
			if (r + 1 < n) {
				if (farm[r + 1][c - 1] == farm[r][c]) {
					if (farm[r + 1][c - 1] != 0 && checktmp[r + 1][c - 1] == 0) {
						if (!distinguishiDfs(n, m, r + 1, c - 1)) {
							return false;
						}
					}
				}
				else if (farm[r + 1][c - 1] > farm[r][c]) {
					return false;
				}
			}
			if (r - 1 >= 0) {
				if (farm[r - 1][c - 1] == farm[r][c]) {
					if (farm[r - 1][c - 1] != 0 && checktmp[r - 1][c - 1] == 0) {
						if (!distinguishiDfs(n, m, r - 1, c - 1)) {
							return false;
						}
					}
				}
				else if (farm[r - 1][c - 1] > farm[r][c]) {
					return false;
				}
			}
		}
		if (r + 1 < n) {
			if (farm[r + 1][c] == farm[r][c]) {
				if (farm[r + 1][c] != 0 && checktmp[r + 1][c] == 0) {
					if (!distinguishiDfs(n, m, r + 1, c)) {
						return false;
					}
				}
			}
			else if (farm[r + 1][c] > farm[r][c]) {
				return false;
			}
		}
		if (r - 1 >= 0) {
			if (farm[r - 1][c] == farm[r][c]) {
				if (farm[r - 1][c] != 0 && checktmp[r - 1][c] == 0) {
					if (!distinguishiDfs(n, m, r - 1, c)) {
						return false;
					}
				}
			}
			else if (farm[r - 1][c] > farm[r][c]) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int n, int m, int r, int c, int key) {
	check[r][c] = 1;
	if (r < 0 || r > n || c < 0 || c > m) {
		return;
	}
	if (c + 1 < m) {
		if (check[r][c + 1] == 0 && farm[r][c + 1] == farm[r][c]) {
			dfs(n, m, r, c + 1, key);
		}
		if (r + 1 < n) {
			if (check[r + 1][c + 1] == 0 && farm[r + 1][c + 1] == farm[r][c]) {
				dfs(n, m, r + 1, c + 1, key);
			}
		}
		if (r - 1 >= 0) {
			if (check[r - 1][c + 1] == 0 && farm[r - 1][c + 1] == farm[r][c]) {
				dfs(n, m, r - 1, c + 1, key);
			}
		}
	}

	if (c - 1 >= 0) {
		if (check[r][c - 1] == 0 && farm[r][c - 1] == farm[r][c]) {
			dfs(n, m, r, c - 1, key);
		}

		if (r + 1 < n) {
			if (check[r + 1][c - 1] == 0 && farm[r + 1][c - 1] == farm[r][c]) {
				dfs(n, m, r + 1, c - 1, key);
			}
		}

		if (r - 1 >= 0) {
			if (check[r - 1][c - 1] == 0 && farm[r - 1][c - 1] == farm[r][c]) {
				dfs(n, m, r - 1, c - 1, key);
			}
		}
	}
	if (r - 1 >= 0) {
		if (check[r - 1][c] == 0 && farm[r - 1][c] == farm[r][c]) {
			dfs(n, m, r - 1, c, key);
		}
	}

	if (r + 1 < n) {
		if (check[r + 1][c] == 0 && farm[r + 1][c] == farm[r][c]) {
			dfs(n, m, r + 1, c, key);
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> farm[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) {
				if (j + 1 < m) {
					if (farm[i][j + 1] > farm[i][j]) {
						continue;
					}
					if (i + 1 < n) {
						if (farm[i + 1][j + 1] > farm[i][j]) {
							continue;
						}
					}
					if (i - 1 >= 0) {
						if (farm[i - 1][j + 1] > farm[i][j]) {
							continue;
						}
					}
				}
				if (j - 1 >= 0) {
					if (farm[i][j - 1] > farm[i][j]) {
						continue;
					}
					if (i + 1 < n) {
						if (farm[i + 1][j - 1] > farm[i][j]) {
							continue;
						}
					}
					if (i - 1 >= 0) {
						if (farm[i - 1][j - 1] > farm[i][j]) {
							continue;
						}
					}
				}
				if (i + 1 < n) {
					if (farm[i + 1][j] > farm[i][j]) {
						continue;
					}
				}
				if (i - 1 >= 0) {
					if (farm[i - 1][j] > farm[i][j]) {
						continue;
					}
				}

				clearcheck(n, m);
				if (distinguishiDfs(n, m, i, j)) {
					dfs(n, m, i, j, farm[i][j]);
				}

			}
		}
	}
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) {
				countcheck(n, m, i, j);
				count++;
			}
		}
	}


	cout << count;

}