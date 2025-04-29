#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int ans = 2;
    for(int i=1; i<=n; i++) {
        ans = 2 * ans - 1;
    }
    printf("%d", ans * ans);
}