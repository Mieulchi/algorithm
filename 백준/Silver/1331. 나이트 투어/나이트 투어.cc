#include <iostream>
#include <algorithm>
using namespace std;

string s;
int mat[6][6];
string ans = "Valid";

void solve() {
	cin >> s;
	int sx, sy;
	sx = (s[0] - 'A');
	sy = (s[1] - '1');
	mat[sx][sy] = 1;
	int x, y;
	int prevx = sx, prevy = sy;
	for (int i = 1; i < 36; i++) {
		cin >> s;
		x = (s[0] - 'A');
		y = (s[1] - '1');
		mat[x][y] = 1;

		if (abs(x - prevx) == 1) {
			if (abs(y - prevy) != 2) {
				ans = "Invalid";
				break;
			}
		}
		else if (abs(x - prevx) == 2) {
			if (abs(y - prevy) != 1) {
				ans = "Invalid";
				break;
			}
		}
		else {
			ans = "Invalid";
			break;
		}
		prevx = x;
		prevy = y;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!mat[i][j]) {
				ans = "Invalid";
				break;
			}
		}
		if (ans == "Invalid") {
			break;
		}
	}
	if (abs(x - sx) == 1) {
		if (abs(y - sy) != 2) {
			ans = "Invalid";
		}
	}
	else if (abs(x - sx) == 2) {
		if (abs(y - sy) != 1) {
			ans = "Invalid";
		}
	}
	else {
		ans = "Invalid";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	cout << ans;
}