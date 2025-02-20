#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];

struct coor {
	int r;
	int c;
};

queue<coor> q;
queue<coor> newq;

void tomato(int r, int c) {
	coor tmp = q.front();

	if (tmp.r + 1 < r) {
		if (box[tmp.r + 1][tmp.c] == 0) {
			box[tmp.r + 1][tmp.c] = 1;
			coor next = { 0, 0 };
			next.r = tmp.r + 1;
			next.c = tmp.c;
			newq.push(next);
		}
	}
	if (tmp.r - 1 >= 0) {
		if (box[tmp.r - 1][tmp.c] == 0) {
			box[tmp.r - 1][tmp.c] = 1;
			coor next = { 0, 0 };
			next.r = tmp.r - 1;
			next.c = tmp.c;
			newq.push(next);
		}
	}
	if (tmp.c + 1 < c) {
		if (box[tmp.r][tmp.c + 1] == 0) {
			box[tmp.r][tmp.c + 1] = 1;

			coor next = { 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c + 1;
			newq.push(next);
		}
	}
	if (tmp.c - 1 >= 0) {
		if (box[tmp.r][tmp.c - 1] == 0) {
			box[tmp.r][tmp.c - 1] = 1;
			coor next = { 0, 0 };
			next.r = tmp.r;
			next.c = tmp.c - 1;
			newq.push(next);
		}
	}

	q.pop();
}

int main() {
    ios_base::sync_with_stdio(false);

	cin.tie(NULL);
    
	int c, r;
	cin >> c >> r;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				coor c = { 0, 0 };
				c.r = i;
				c.c = j;
				q.push(c);
			}
		}
	}

	int day = 0;
	while (!q.empty()) {
		tomato(r, c);
	}

	while (!newq.empty()) {
		while (!newq.empty()) {
			coor tmp = newq.front();
			q.push(tmp);
			newq.pop();
		}

		while (!q.empty()) {
			tomato(r, c);
		}
		day++;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (box[i][j] == 0) {
				day = -1;
			}
		}
	}

	cout << day;
}