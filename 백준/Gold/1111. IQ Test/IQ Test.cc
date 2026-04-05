#include <iostream>
using namespace std;

int nums[51];

int getAbs(int n) {
	if (n < 0) {
		n *= -1;
	}

	return n;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	if (n == 1) {
		cout << 'A';
	}
	else if (n == 2) {
		if (nums[0] == nums[1]) {
			cout << nums[0];
		}
		else {
			cout << 'A';
		}
	}
	else {
		int success = 1;
		int a, b;
		if (nums[1] == nums[2] || nums[1] == nums[0]) {
			a = 0;
			b = nums[1];
		}
		else {
			a = (nums[2] - nums[1]) / (nums[1] - nums[0]);
			b = nums[1] - nums[0] * a;
		}
		if (getAbs(nums[2] - nums[1]) < getAbs(nums[1] - nums[0]) && (nums[2] - nums[1] != 0)) {
			cout << 'B';
		}
		else {
			int i;
			for (i = 0; i < n - 1; i++) {
				if (nums[i + 1] != nums[i] * a + b) {
					success = 0;
					break;
				}
			}
			if (success == 0) {
				cout << 'B';
			}
			else {
				cout << a * nums[i] + b;
			}
		}
	}
	}