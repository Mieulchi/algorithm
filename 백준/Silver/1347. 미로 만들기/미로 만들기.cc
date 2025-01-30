#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
string s;
char maze[101][101];

void solve() {
	//    0 
	//  3 x 1
	//    2
	int dir = 2;
	int x = 50, y = 50;
	maze[x][y] = '.';
	int xmax = 50, xmin = 50, ymax = 50, ymin = 50;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (s[i] == 'R') {
			dir = (dir + 1) % 4;
		}
		else {
			if (dir == 0) {
				y -= 1;
			}
			if (dir == 1) {
				x += 1;
			}
			if (dir == 2) {
				y += 1;
			}
			if (dir == 3) {
				x -= 1;
			}
			if (x > xmax) {
				xmax = x;
			}
			if (x < xmin) {
				xmin = x;
			}
			if (y > ymax) {
				ymax = y;
			}
			if (y < ymin) {
				ymin = y;
			}
			maze[y][x] = '.';
		}
	}

	for (int i = ymin; i <= ymax; i++) {
		for (int j = xmin; j <= xmax; j++) {
			if (maze[i][j]){
				cout << maze[i][j];
			}
			else {
				cout << '#';
			}
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	solve();
}