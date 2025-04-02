#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int n1, n2, n3, n4, n5;
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    
    printf("%d %d %d %d %d", n1 - a * b, n2 - a * b, n3 - a * b, n4 - a * b, n5 - a * b);
}