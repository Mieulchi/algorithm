#include <algorithm>
using namespace std;

#include <stdio.h>


int dp[3];

int main() {
    int n;
    scanf("%d", &n);
    
    int r, g, b;
    int N=n--;
    while(N--) {
        scanf("%d %d %d", &r, &g, &b);
        int tmp[3];
        if (N!=n) {
            tmp[0] = r + min(dp[1], dp[2]);
            tmp[1] = g + min(dp[0], dp[2]);
            tmp[2] = b + min(dp[0], dp[1]);
            
            for(int i=0;i<3;i++){
                dp[i] = tmp[i];
            }
        }
        else {
            dp[0] = r;
            dp[1] = g;
            dp[2] = b;
        }
    }
    
    printf("%d", min({dp[0], dp[1], dp[2]}));
    
}