#include <iostream>
#include <algorithm>
using namespace std;

int n;
int mx, mn;
int dp[2][2][3];

void solve() {
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        dp[0][1][0] = max(dp[0][0][0], dp[0][0][1]) + a;
        dp[0][1][1] = max({ dp[0][0][0], dp[0][0][1], dp[0][0][2] }) + b;
        dp[0][1][2] = max(dp[0][0][1], dp[0][0][2]) + c;

        dp[0][0][0] = dp[0][1][0];
        dp[0][0][1] = dp[0][1][1];
        dp[0][0][2] = dp[0][1][2];  
        
        dp[1][1][0] = min(dp[1][0][0], dp[1][0][1]) + a;
        dp[1][1][1] = min({ dp[1][0][0], dp[1][0][1], dp[1][0][2] }) + b;
        dp[1][1][2] = min(dp[1][0][1], dp[1][0][2]) + c;

        dp[1][0][0] = dp[1][1][0];
        dp[1][0][1] = dp[1][1][1];
        dp[1][0][2] = dp[1][1][2];
    }
    mx = max({ dp[0][0][0], dp[0][0][1],dp[0][0][2] });
    mn = min({ dp[1][0][0], dp[1][0][1],dp[1][0][2] });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve();
    cout << mx << ' ' << mn;
    
}