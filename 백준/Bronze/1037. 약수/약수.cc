#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		int ret;
		cin >> ret;
		if (ret == 1) {
			cout << 1 ;
		}
		else { 
			if (ret % 2 == 0) {
				cout << ret * 2;
			}
			else {
				cout << ret * ret;
			}
		}
		return 0;
	}
	else if (n == 2) {
		int a, b;
		cin >> a >> b;
		cout << a * b;
		return 0;
	}
	else {
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int min = a[0];
		int max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
			if (a[i] < min) {
				min = a[i];
			}
		}

		printf("%d\n", max * min);

		delete [] a;
	}
}