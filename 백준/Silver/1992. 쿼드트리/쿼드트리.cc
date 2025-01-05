#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char video[64][64];
string ans;

void solve(int r, int c, int size) {
	int flag = 1;
	char start = video[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (video[i][j] != start) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (flag) {
		ans += start;
	}
	else {
		ans += '(';
		solve(r, c, size / 2);
		solve(r, c + size / 2, size / 2);
		solve(r + size / 2, c, size / 2);
		solve(r + size / 2, c + size / 2, size / 2);
		ans += ')';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			video[i][j] = s[j];
		}
	}

	if (n == 1) {
		ans = video[0][0];
	}
	else {
		solve(0, 0, n);
	}

	cout << ans;
}