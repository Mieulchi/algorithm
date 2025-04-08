#include <stdio.h>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if (m + 15 < 60) {
        printf("%d %d", (h + 23) % 24, m + 15);   
    }
    else {
        printf("%d %d", h, (m + 15) % 60);
    }
}