#include <stdio.h>

int main() {
	int l, a, b, c, d;
	//20 25 30 6 8
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	//25문제중 하루 6문제
	int korean = a / c;
	if (a % c) { // true
		korean++;
	}

	//24 3일 + 6문제 1 일
	int math = b / d;
	if (b % d) {
		math++;
	}

	if (l - korean < l - math) {
		printf("%d", l - korean);
	}
	else {
		printf("%d", l - math);
	}
}