#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int j = 0, k = 0;
		for (j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i ; k++) {
			printf("*");
		}
		printf("\n");
	}
}