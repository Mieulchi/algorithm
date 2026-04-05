#include <iostream>
#include <string>
using namespace std;

int main() {
	int sum = 0;
	int min = -1;
	int n;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 == 1) {
			sum += n;
			if (n < min || min == -1) {
				min = n;
			}
		}
	}
	if (min == -1) {
		printf("-1");
	}
	else {
		printf("%d\n%d\n", sum, min);
	}
}