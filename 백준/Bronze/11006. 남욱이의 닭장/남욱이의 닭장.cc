#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
	    int n, m;
	    scanf("%d %d", &n, &m);
	    int x = 2 * m - n;
	    printf("%d %d\n", x, m - x);
    }
}