#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int ans = n / 5;
    if (n % 5) {
        ans++;
    }
    printf("%d", ans);
}