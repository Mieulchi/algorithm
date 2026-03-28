#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a; char ch;
    while(n--){
        scanf("%d %c", &a, &ch);
        while(a--){
            printf("%c", ch);
        }
        printf("\n");
    }
}