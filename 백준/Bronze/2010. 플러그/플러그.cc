#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int t;
    int ans = 0;
	while (n--) {
		scanf("%d", &t);
		ans += t - 1;
	}
    ans++;
    printf("%d", ans);
}