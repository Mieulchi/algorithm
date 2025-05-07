#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int t;
	while (true) {
		scanf("%d", &t);
		if (!t) {
			break;
		}
		if (t % n) {
			printf("%d is NOT a multiple of %d.\n", t, n);
		}
		else {
			printf("%d is a multiple of %d.\n", t, n);
		}
	}
}