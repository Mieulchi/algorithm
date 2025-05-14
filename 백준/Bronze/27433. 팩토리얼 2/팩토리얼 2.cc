#include <stdio.h>

long long recursive(int n) {
	if (n == 0) {
		return 1;
	}
	return n * recursive(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);

	long long result = recursive(n);
	printf("%lld", result);

}