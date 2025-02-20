#include <iostream>
using namespace std;

int a, k;
int dp[1000001];

void solve() {
    int i=a;
    while(i<=k) {
        if(i+1<=k && (!dp[i+1] || dp[i+1] > dp[i] + 1)) {
            dp[i + 1] = dp[i] + 1;
        }
        if(i*2<=k && (!dp[i*2] || dp[i*2] > dp[i] + 1)) {
            dp[i * 2] = dp[i] + 1;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>a>>k;
    
    solve();
    
    cout<<dp[k];
    
}