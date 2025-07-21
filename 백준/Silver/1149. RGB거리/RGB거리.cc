#include <stdio.h>

int arr[3][1000];
int dp[3][1000];

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
        if (i) {
            dp[0][i] = arr[0][i] + (dp[2][i - 1] > dp[1][i - 1] ? dp[1][i - 1] : dp[2][i - 1]);
            dp[1][i] = arr[1][i] + (dp[2][i - 1] > dp[0][i - 1] ? dp[0][i - 1] : dp[2][i - 1]);
            dp[2][i] = arr[2][i] + (dp[1][i - 1] > dp[0][i - 1] ? dp[0][i - 1] : dp[1][i - 1]);
        }
        else {
            dp[0][0] = arr[0][0];
            dp[1][0] = arr[1][0];
            dp[2][0] = arr[2][0];
        }
    }
    
    printf("%d", dp[1][n - 1] > dp[0][n - 1] ? (dp[2][n - 1] > dp[0][n - 1] ? dp[0][n - 1] : dp[2][n - 1] ): (dp[2][n - 1] > dp[1][n - 1] ? dp[1][n - 1] : dp[2][n - 1]));
    
}