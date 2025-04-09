#include <stdio.h>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int cmp1, cmp2, cmp3, cmp4;
	cmp1 = x;
	cmp2 = w - x;
	cmp3 = y;
	cmp4 = h - y;
	int ans;
	if (cmp1 < cmp2) {
		if (cmp3 < cmp4) {
			if (cmp3 < cmp1) {
				ans = cmp3;
			}
			else {
				ans = cmp1;
			}
		}
		else {
			if (cmp4 < cmp1) {
				ans = cmp4;
			}
			else {
				ans = cmp1;
			}
		}
	}
	else {
		if (cmp3 < cmp4) {
			if (cmp3 < cmp2) {
				ans = cmp3;
			}
			else {
				ans = cmp2;
			}
		}
		else {
			if (cmp4 < cmp2) {
				ans = cmp4;
			}
			else {
				ans = cmp2;
			}
		}
	}
	printf("%d", ans);
}