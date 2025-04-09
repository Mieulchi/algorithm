#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans;
	if (a == b && b == c) {
		ans = 10000 + a * 1000;
	}
	else if (a == b || b == c || a == c) {
		int t;
		if (a == b) {
			t = a;
		}
		else if (b == c) {
			t = b;
		}
		else {
			t = c;
		}
		ans = 1000 + t * 100;
	}
	else {
		int t;
		if (a > b) {
			if (a > c) {
				t = a;
			}
			else {
				t = c;
			}
		}
		else {
			if (b > c) {
				t = b;
			}
			else {
				t = c;
			}

		}
		ans = t * 100;
	}
	printf("%d", ans);
}