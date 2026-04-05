#include <iostream>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;

	long long buildings[52] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}

	int counts[51] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (j == i + 1) {
				counts[i]++;
				counts[j]++;
			}
			else {

 				int flag = 1;
				for (int k = i + 1; k < j; k++) {
					if ((j - i) * (buildings[k] - buildings[i]) >= (k - i) * (buildings[j] - buildings[i])) {
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					counts[i]++;
					counts[j]++;
				}
			}
		}
	}

	int max = counts[0];
	for (int i = 1; i < n; i++) {
		if (counts[i] > max) {
			max = counts[i];
		}
	}
	cout << max;
}