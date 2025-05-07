#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int t;
	while (n--) {
		scanf("%d", &t);
		while (t--) {
			printf("=");
		}
		printf("\n");
	}
}