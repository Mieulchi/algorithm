#include <iostream>
using namespace std;

int main() {
	int k, t;
	cin >> k >> t;

	int count = 0;
	int* a = new int[k];

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	int sum = 0;
	int i = 0;
	while (sum < t && i < k) {
		sum += a[i];
		i++;
		count++;
	}
	if (sum > t) {
		count--;
	}

	cout << count;

}