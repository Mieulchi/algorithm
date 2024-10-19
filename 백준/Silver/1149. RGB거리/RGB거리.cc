#include <iostream>
#include <cmath>
using namespace std;

int r[1001];
int g[1001];
int b[1001];

int main() {
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	int sum[3] = { 0 };
	int min[3] = { 0 };

	min[0] = r[0];
	min[1] = g[0];
	min[2] = b[0];
	for (int i = 1; i < k; i++) {
		sum[0] = sum[1] = sum[2] = 0;

		if (min[0] < min[1]) {
			sum[2] += min[0] + b[i];
		}
		else {
			sum[2] += min[1] + b[i];
		}
		if (min[1] < min[2]) {
			sum[0] += min[1] + r[i];
		}
		else {
			sum[0] += min[2] + r[i];
		}
		if (min[2] < min[0]) {
			sum[1] += min[2] + g[i];
		}
		else {
			sum[1] += min[0] + g[i];
		}

		min[0] = sum[0];
		min[1] = sum[1];
		min[2] = sum[2];
	}

	int result = 0;
	if (min[0] < min[1]) {
		if (min[0] < min[2]) {
			result = min[0];
		}
		else {
			result = min[2];
		}
	}
	else {
		if (min[1] < min[2]) {
			result = min[1];
		}
		else {
			result = min[2];
		}
	}

	cout << result;
}