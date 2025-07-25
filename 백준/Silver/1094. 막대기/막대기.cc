#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=0;i<=6;i++){
        if ((n>>i)&1){ans++;}
    }
    printf("%d", ans);
}