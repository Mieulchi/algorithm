#include <stdio.h>

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	int minkook = a + b + c + d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	int manse = a + b + c + d;

	//if () 괄호 안의 값이 true이면 {} 내의 코드 실행
	if (minkook > manse) {
		printf("%d", minkook);
	}
	else {
		printf("%d", manse);
	}
}