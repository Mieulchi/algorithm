#include <stdio.h>

int main() {	
    int n;
	scanf("%d", &n);
    
	if (!n) {
		printf("0");
		return 0;
	}
	if (n == 1) {
		printf("1");
		return 0;
	}

	int appeared = 0;
	for (int i = 2; i <= 9; i++) {
        if (n / i > 9) {
        	continue;
        }
		if (n % i == 0) {
			appeared = 1;
			break;
		}
	}
	
	printf("%d", appeared);
}