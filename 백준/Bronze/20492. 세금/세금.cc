#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d %d", n * 78 / 100, n * 4 / 5 + (n - (n * 4 / 5)) * 78 / 100);
}