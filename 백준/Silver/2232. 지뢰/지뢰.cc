#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[50001];
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        if (i + 1 <= n && i - 1 > 0) {
            if (arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1]){
                printf("%d\n", i);
            }
        }
        else if (i + 1 <= n) {
            if (arr[i] >= arr[i + 1]){
                printf("%d\n", i);
            }
        }
        else if (i - 1 > 0) {
            if (arr[i] >= arr[i - 1]){
                printf("%d\n", i);
            }
        }
        else {
            printf("%d", i);
        }
    }
}