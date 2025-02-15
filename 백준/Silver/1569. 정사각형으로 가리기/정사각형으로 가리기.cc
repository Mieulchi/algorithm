#include <iostream>
#include <algorithm>
using namespace std;

int n;
int xmax = -1001;
int xmin = 1001;
int ymax = -1001;
int ymin = 1001;
int x[50];
int y[50];
int ans;

void solve() {
	int c1(0), c2(0), c3(0), c4(0);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > xmax) {
			xmax = x[i];
		}
		if (x[i] < xmin) {
			xmin = x[i];
		}
		if (y[i] > ymax) {
			ymax = y[i];
		}
		if (y[i] < ymin) {
			ymin = y[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (x[i] == xmax || x[i] == xmin) {
			if (y[i] != ymax && y[i] != ymin) {
				x[i] == xmax ? c2++ : c4++;
			}
		}
		else if (y[i] == ymax || y[i] == ymin) {
			if (x[i] != xmax && x[i] != xmin) {
				y[i] == ymax ? c1++ : c3++;
			}
		}
		else {
			ans = -1;
			break;
		}
	}
	if (ans != -1) {
		if (xmax - xmin == ymax - ymin) {
			ans = xmax - xmin;
		}
		else {
			if (xmax - xmin > ymax - ymin) {
				if (c1 && c3) {
					ans = -1;
				}
				else {
					ans = xmax - xmin;
				}
			}
			else {
				if (c2 && c4) {
					ans = -1;
				}
				else {
					ans = ymax - ymin;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
	
	cout << ans;
}