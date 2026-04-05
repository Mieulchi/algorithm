#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int* result = new int[n];

	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}

	//2 1 1 0 -> 4 2 1 3

	result[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		int count = a[i] + 1;
		int j;
		for (j = 0; j < n; j++) {
			if (result[j] == 0 || result[j] > i + 1) {
				count--;
			}
			if (!count) {
				break;
			}
		}
		result[j] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

	delete[] a;
	delete[] result;
}