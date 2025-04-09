#include <stdio.h>

int main() {
	int h, m;
	scanf("%d %d", &h, &m);

	// -45분 == + 15분
	// +15분 했는데 m이 60 이상이면 시간은 -1 안해도 됨
	// -45분 했는데 m이 0 이상이라는 말이니까
	if (m + 15 >= 60) {
		m = (m + 15) % 60;
	}
	else {
        m += 15;
		h = (h + 23) % 24;
	}

	printf("%d %d", h, m);
}
