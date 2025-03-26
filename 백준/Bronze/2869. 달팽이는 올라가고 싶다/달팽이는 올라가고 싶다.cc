#include <stdio.h>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int ans = 0;
    ans += (v - a) / (a - b);
    ans += (v - a) % (a - b) ? 1 : 0;
    ans++;
    printf("%d", ans);
}