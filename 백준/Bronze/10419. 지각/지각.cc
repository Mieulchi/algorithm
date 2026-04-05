#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;

		int sum = 0;
		int n = 0;
		while (n + n * n <= t) {
			n++;
		}
		n--;
		cout << n << '\n';
	}
}