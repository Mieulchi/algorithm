#include <iostream>
#include <string>
using namespace std;

int main() {
	int k;
	int h, w, n;


	cin >> k;


	for (int i = 0; i < k; i++) {
		cin >> h >> w >> n;

		if (n % h != 0) {
			printf("%d\n", n % h * 100 + n / h + 1);
		}
		else {
			printf("%d\n", h * 100 + n / h );
		}
	}

}