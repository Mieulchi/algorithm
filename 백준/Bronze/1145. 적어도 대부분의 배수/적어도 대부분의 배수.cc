#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int get_gcm(int a, int b) {
	int n = 0;
		if (a > b) {
			while (true) {
				n = a % b;
				if (n == 0) {
					return b;
					break;
				}
				a = b;
				b = n;
			}
		}
		else {
			while (true) {
			n = b % a;
			if (n == 0) {
				return a;
				break;
			}
			b = a;
			a = n;
		}
	}
}

int get_lcm(int a, int b) {
	if (a > b) {
		if (a % b == 0) {
			return a;
		}
		else {
			int n = get_gcm(a, b);
			return n * a / n * b / n;
		}
	}
	else {
		if (b % a == 0) {
			return b;
		}
		else {
			int n = get_gcm(a, b);
			return n * a / n * b / n;
		}
	}
}

int main() {
	int a[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	int mLcm = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (get_lcm(a[i], get_lcm(a[j], a[k])) < mLcm || mLcm == 0) {
					mLcm = get_lcm(a[i], get_lcm(a[j], a[k]));
				}
			}
		}
	}
	printf("%d", mLcm);
}