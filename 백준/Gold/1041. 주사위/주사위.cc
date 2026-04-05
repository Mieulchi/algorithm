#include <iostream>
#include <algorithm>
using namespace std;

int nums[7];
int twos[13];
int threes[9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long k;
	cin >> k;

	for (int i = 0; i < 6; i++) {
		cin >> nums[i];
	}


	long long sum = 0;
	if (k == 1) {
		int max = nums[0];
		
		sort(nums, nums + 6);
		for (int i = 0; i < 5; i++) {
			sum += nums[i];
		}
	}
	else {

		long long three = 4;
		long long two = 4 * (k - 1) + 4 * (k - 2);
		long long one = (k - 2) * (k - 2) * 5 + (k - 2) * 4;

		int min2 = nums[0] + nums[1];
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 6; j++) {
				if (i + j != 5) {
					if (nums[i] + nums[j] < min2) {
						min2 = nums[i] + nums[j];
					}
				}
			}
		}


		int min3 = 0;
		
		if (nums[0] < nums[5]) {
			min3 += nums[0];
		}
		else {
			min3 += nums[5];
		}

		int tmp = nums[1] + nums[2];
		if (nums[2] + nums[4] < tmp) {
			tmp = nums[2] + nums[4];
		}
		if (nums[4] + nums[3] < tmp) {
			tmp = nums[3] + nums[4];
		}
		if (nums[1] + nums[3] < tmp) {
			tmp = nums[1] + nums[3];
		}

		min3 += tmp;
			
		int min = nums[0];
		for (int i = 1; i < 6; i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
		}

		sum += min * one;
		sum += min2 * two;
		sum += min3 * three;
	}

	cout << sum;
}