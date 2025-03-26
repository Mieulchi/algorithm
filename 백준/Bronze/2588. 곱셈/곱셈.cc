#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	// 385/ 10 == 38 ... 5
	// 385   8
	printf("%d\n", a * (b % 10));
	printf("%d\n", a * (b % 100 / 10));
	printf("%d\n", a * (b / 100));
	printf("%d\n", a * b);
}