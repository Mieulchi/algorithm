#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int sect(int n, int r, int c) {
	int sum = 0;
	if (n == 2) {
		return 2 * (r % 2) + c % 2;
	}
	else {
		if (r < n / 2 && c < n / 2) {
			sum = 0;

		}
		else if (r < n / 2 && c >= n / 2) {
			sum = (n / 2) * (n / 2);
			c -= n / 2;
		}
		else if (r >= n / 2 && c < n / 2) {
			sum = (n / 2) * (n / 2) * 2;
			r -= n / 2;
		}
		else if (r >= n / 2 && c >= n / 2) {
			sum = (n / 2) * (n / 2) * 3;
			r -= n / 2;
			c -= n / 2;
		}

		return sum + sect(n / 2, r, c);
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	//4 7 7

	int size = 1;
	for (int i = 0; i < n; i++) {
		size *= 2;
	}

	//16 7 7
	int idx = sect(size, r, c);
	
	cout << idx;
}