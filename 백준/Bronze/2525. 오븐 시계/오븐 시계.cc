#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c;
    scanf("%d", &c);
    printf("%d %d", (a + (b + c) / 60) % 24, (b + c) % 60);
}