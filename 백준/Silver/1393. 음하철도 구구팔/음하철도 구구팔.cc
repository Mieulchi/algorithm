#include <iostream>
#include <algorithm>
using namespace std;

int x, y;
int tx, ty, dx, dy;

void dvByGcd() {
	int tmpx = abs(dx), tmpy = abs(dy);
	if (tmpx < tmpy) {
		int swp = tmpx;
		tmpx = tmpy;
		tmpy = swp;
	}
	while (tmpy) {
		int rem = tmpy;
		tmpy = tmpx % tmpy;
		tmpx = rem;
	}
	dx /= tmpx;
	dy /= tmpx;
}

void solve() {
	if (dx != 0 && dy != 0) {
		dvByGcd();
	}
	else {
		if (dx == 0) {
			if (dy < 0) {
				dy = -1;
			}
			else {
				dy = 1;
			}
		}
		else {
			if (dx < 0) {
				dx = -1;
			}
			else {
				dx = 1;
			}
		}
	}

	int dist = (tx - x) * (tx - x) + (ty - y) * (ty - y);
	while (true) {
		tx += dx;
		ty += dy;
		if ((tx - x) * (tx - x) + (ty - y) * (ty - y) > dist) {
			tx -= dx;
			ty -= dy;
			break;
		}
		else {
			dist = (tx - x) * (tx - x) + (ty - y) * (ty - y);
		}
	}
	cout << tx << ' ' << ty;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	cin >> tx >> ty >> dx >> dy;
	if (dx == 0 && dy == 0) {
		cout << tx << ' ' << ty;
	}
	else {
		solve();
	}
}