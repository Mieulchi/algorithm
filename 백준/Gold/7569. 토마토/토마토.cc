#include <iostream>
#include <queue>
using namespace std;

int box[101][101][101];

struct coor {
	int r;
	int c;
	int h;
};

queue<coor> q;
queue<coor> newq;

void tomato(int r, int c, int h) {
	coor tmp = q.front();

	if (tmp.r + 1 < r) {
		if (box[tmp.r + 1][tmp.c][tmp.h] == 0) {
			box[tmp.r + 1][tmp.c][tmp.h] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r + 1;
			next.c = tmp.c;
			next.h = tmp.h;
			newq.push(next);
		}
	}
	if (tmp.r - 1 >= 0) {
		if (box[tmp.r - 1][tmp.c][tmp.h] == 0) {
			box[tmp.r - 1][tmp.c][tmp.h] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r - 1;
			next.c = tmp.c;
			next.h = tmp.h;
			newq.push(next);
		}
	}
	if (tmp.c + 1 < c) {
		if (box[tmp.r][tmp.c + 1][tmp.h] == 0) {
			box[tmp.r][tmp.c + 1][tmp.h] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c + 1;
			next.h = tmp.h;
			newq.push(next);
		}
	}
	if (tmp.c - 1 >= 0) {
		if (box[tmp.r][tmp.c - 1][tmp.h] == 0) {
			box[tmp.r][tmp.c - 1][tmp.h] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c - 1;
			next.h = tmp.h;
			newq.push(next);
		}
	}
	if (tmp.h - 1 >= 0) {
		if (box[tmp.r][tmp.c][tmp.h - 1] == 0) {
			box[tmp.r][tmp.c][tmp.h - 1] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c;
			next.h = tmp.h - 1;
			newq.push(next);
		}
	}
	if (tmp.h + 1 < h) {
		if (box[tmp.r][tmp.c][tmp.h + 1] == 0) {
			box[tmp.r][tmp.c][tmp.h + 1] = 1;
			coor next = { 0, 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c;
			next.h = tmp.h + 1;
			newq.push(next);
		}
	}

	q.pop();
}

int main() {
	int c, r, h;
	cin >> c >> r >> h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					coor c = { 0, 0, 0 };
					c.r = i;
					c.c = j;
					c.h = k;
					q.push(c);
				}
			}
		}
	}

	int day = 0;
	while (!q.empty()) {
		tomato(r, c, h);
	}

	while (!newq.empty()) {
		while (!newq.empty()) {
			coor tmp = newq.front();
			q.push(tmp);
			newq.pop();
		}

		while (!q.empty()) {
			tomato(r, c, h);
		}
		day++;
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (box[i][j][k] == 0) {
					day = -1;
				}
			}
		}
	}

	cout << day;
}