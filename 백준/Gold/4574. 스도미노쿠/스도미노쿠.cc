#include <iostream>
using namespace std;

int n;
int board[9][9];
int domino[10][10];
int flag;
int num;

void init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = 0;
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			domino[i][j] = 0;
		}
	}
}

int check(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 9; i++) {
		if (i != c && board[r][i] == board[r][c]) {
			ret = 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i != r && board[i][c] == board[r][c]) {
			ret = 0;
		}
	}
	int sr = 3 * (r / 3), sc = 3 * (c / 3);
	for (int i = sr; i < sr + 3; i++) {
		for (int j = sc; j < sc + 3; j++) {
			if (r != i && c != j) {
				if (board[i][j] == board[r][c]) {
					ret = 0;
				}
			}
		}
	}
	return ret;
}

void make(int cnt) {
	if (cnt == 36 - n) {
		flag = 1;
		cout << "Puzzle " << num << '\n';
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
	else {
		int r = 0, c = 0;
		for (int i = 0; i < 9; i++) {
			int flag = 0;
			for (int j = 0; j < 9; j++) {
				if (!flag && !board[i][j]) {
					r = i; c = j;
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!board[r + 1][c] || !board[r][c + 1]) {
			for (int i = 1; i < 10; i++) {
				board[r][c] = i;
				if (!check(r, c)) {
					board[r][c] = 0;
					continue;
				}

				if (!board[r + 1][c] || !board[r][c + 1]) {
					if (r + 1 < 9 && !board[r + 1][c]) {
						for (int j = 1; j < 10; j++) {
							if (!domino[i][j]) {
								board[r + 1][c] = j;
								domino[j][i] = 1;
								domino[i][j] = 1;
								if (check(r + 1, c)) {
									make(cnt + 1);
								}
								domino[j][i] = 0;
								domino[i][j] = 0;
								board[r + 1][c] = 0;
							}
						}
					}
					if (c + 1 < 9 && !board[r][c + 1]) {
						for (int j = 1; j < 10; j++) {
							if (!domino[i][j]) {
								board[r][c + 1] = j;
								domino[j][i] = 1;
								domino[i][j] = 1;
								if (check(r, c + 1)) {
									make(cnt + 1);
								}
								domino[j][i] = 0;
								domino[i][j] = 0;
								board[r][c + 1] = 0;
							}
						}
					}
				}
				if (flag) {
					break;
				}
				else {
					board[r][c] = 0;
				}
			}
		}
	}
}

void solve() {
	flag = 0;
	int n1, n2;
	string s1, s2;
	int t = n;
	init();
	while (t--) {
		cin >> n1 >> s1 >> n2 >> s2;
		domino[n1][n2] = 1;
		domino[n2][n1] = 1;
		board[s1[0] - 'A'][s1[1] - '1'] = n1;
		board[s2[0] - 'A'][s2[1] - '1'] = n2;
	}
	string s;
	for (int i = 1; i <= 9; i++) {
		cin >> s;
		board[s[0] - 'A'][s[1] - '1'] = i;
	}
	make(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	num = 1;
	while (num) {
		cin >> n;
		if (!n) {
			break;
		}
		solve();
		num++;
	}
}