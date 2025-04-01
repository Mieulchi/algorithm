#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    int total = 1000 - n;
    ans += total / 500;
    total %= 500;
    ans += total / 100;
    total %= 100;
    ans += total / 50;
    total %= 50;
    ans += total / 10;
    total %= 10;
    ans += total / 5;
    total %= 5;
    ans += total / 1;
    total %= 1;
    
    printf("%d", ans);
}