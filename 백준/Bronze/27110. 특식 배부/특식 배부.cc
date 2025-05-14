#include <stdio.h>

int main() {
    int n;
scanf("%d", &n);
int a, b, c;
scanf("%d %d %d", &a, &b, &c);
//각 치킨을 n마리씩 시키니까 n==5면 후라이드5, 간장5, 양념5임
int ans = 0;
//후라이드 원하는사람이 n보다 많으면 최대 n명 먹음, n보다 적으면 최대 a명 먹음, 간장이랑 양념도 똑같다
ans += a > n ? n : a;
ans += b > n ? n : b;
ans += c > n ? n : c;
printf("%d", ans);
}