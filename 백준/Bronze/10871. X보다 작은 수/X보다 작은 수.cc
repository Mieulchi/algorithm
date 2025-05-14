#include <stdio.h>

int main() {
    int n, x;
scanf("%d %d", &n, &x);

for (int i = 0; i < n; i++) {
	int t;
	scanf("%d", &t);
	if (t < x) {
		printf("%d ", t);
	}
}
}