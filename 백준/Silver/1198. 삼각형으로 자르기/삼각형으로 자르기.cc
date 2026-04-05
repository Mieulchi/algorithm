#include <iostream>
using namespace std;

int x[36];
int y[36];

double getWidth(int a, int b, int c) {
	int key = ((x[a] * y[b] + x[b] * y[c] + x[c] * y[a]
		- x[b] * y[a] - x[c] * y[b] - x[a] * y[c]));
	if (key < 0) {
		key *= -1;
	}


	return double(key / 2.0);
}

int main() {
	//1/2 (x1y2 x2y3 x3 y1 - x2y1 x3y2 x1y3)
	int k;
	cin >> k;

	if (k < 3 || k>35) {
		return 0;
	}

	for (int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
	}

	double max = 0;
	for (int i = 0; i < k - 2; i++) {
		for (int j = i + 1; j < k - 1; j++) {
			for (int l = j + 1; l < k; l++) {
				double width = getWidth(i, j, l);
				if (max < width) {
					max = width;
				}
			}
		}
	}

	printf("%.1f", max);
}