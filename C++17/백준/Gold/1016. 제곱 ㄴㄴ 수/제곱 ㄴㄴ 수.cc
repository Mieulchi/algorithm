#include <iostream>
#include <cmath>
using namespace std;

int check[1000001];

int main() {
	long long min, max;
	cin >> min >> max;


	long long i = 2;
	while (true) {
		if (sqrt(i) == 0.0) {
			continue;
		}
		long long op = i * i;
		
		if (op > max) {
			break;
		}
		
		long long front;

		if (min % op == 0) {
			front = op * (min / op);
		}
		else {
			front = op * ((min / op) + 1);
		}

		for (long long j = front; j <= max; j += op) {
			check[j - min] = 1;
		}
		i++;
	}
	int n = 0;
	for (int i = 0; i < max - min + 1; i++) {
		if (!check[i]) {
			n++;
		}
	}
	cout << n;
}