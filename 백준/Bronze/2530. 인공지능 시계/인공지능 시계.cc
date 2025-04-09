#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d;
	scanf("%d", &d);
	int newA = a, newB = b, newC = c;
	newC = c + d;
	if (newC >= 60) {
		newB += newC / 60;
		newC %= 60;
	}
	if (newB >= 60) {
		newA += newB / 60;
		newB %= 60;
	}
	if (newA >= 24) {
		newA %= 24;
	}
	printf("%d %d %d", newA, newB, newC);
}