#include <iostream>
#include <string>
using namespace std;


int getabs(int n) {
	n < 0 ? n *= -1 : n;

	return n;
}

int getLen(int n) {
	int result = 0;
	while (n > 0) {
		n /= 10;
		result++;
	}

	return result;
}

int main() {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	

	int size;
	
	size = getabs(r1);
	if (getabs(r2) > getabs(size)) {
		size = r2;
	}
	if (getabs(c1) > getabs(size)) {
		size = c1;
	}
	if (getabs(c2) > getabs(size)) {
		size = c2;
	}

	//		1
	//    2   0
	//		3
	int n = 1;
	int pr, pc;
	int startr, startc;
	size = abs(size);
	size *= 2;
	size++;
	pr = pc = size / 2;
	startr = pr;
	startc = pc;

	int** mat = new int* [r2 - r1 + 1];
	for (int i = 0; i < r2 - r1 + 1; i++) {
		mat[i] = new int[c2 - c1 + 1];
		for (int j = 0; j < c2 - c1 + 1; j++) {
			mat[i][j] = 0;
		} 
	}


	int rmin, rmax, cmin, cmax;

	r1 > startr ? rmin = startr - r1: rmin = startr + r1; //0
	r2 > startr ? rmax = r2 - startr  + 1: rmax = startr + r2 + 1; //5
	c1 > startc ? cmin = startc - c1 : cmin = startc + c1; //0
	c2 > startc ? cmax = c2 - startc + 1 : cmax = startc + c2 + 1; //4


	if (pr >= rmin && pr < rmax && pc >= cmin && pc < cmax) {
		mat[pr - rmin][pc - cmin] = n++;
	}
	else {
		n++;
	}



	int direction = 0;
	int interval = 1;
	int count = 0;
	for (; interval < size; count++, direction++) {
		if (direction == 4) {
			direction = 0;
		}
		if (count == 2) {
			count = 0;
			interval++;
		}
		if (direction == 0) {
			for (int j = 0; j < interval; j++) {
				pc++;
				if (pr >= rmin && pr < rmax && pc >= cmin && pc < cmax) {
					mat[pr - rmin][pc - cmin] = n;
				}
				n++;
			}
		}
		else if (direction == 1) {
			for (int j = 0; j < interval; j++) {
				pr--;
				if (pr >= rmin && pr < rmax && pc >= cmin && pc < cmax) {
					mat[pr - rmin][pc - cmin] = n;
				}
				n++;
			}
		}
		else if (direction == 2) {
			for (int j = 0; j < interval; j++) {
				pc--;
				if (pr >= rmin && pr < rmax && pc >= cmin && pc < cmax) {
					mat[pr - rmin][pc - cmin] = n;
				}
				n++;
			}
		}
		else if (direction == 3) {
			for (int j = 0; j < interval; j++) {
				pr++;
				if (pr >= rmin && pr < rmax && pc >= cmin && pc < cmax) {
					mat[pr - rmin][pc - cmin] = n;
				}
				n++;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < r2 - r1 + 1; i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) {	
			if (mat[i][j] > max) {
				max = mat[i][j];
			}
		}
	}

	int len = getLen(max);

	for (int i = 0; i < r2 - r1 + 1; i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) {
			int bnum = len - getLen(mat[i][j]);
			for (int k = 0; k < bnum; k++) {
				cout << ' ';
			}
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}

}