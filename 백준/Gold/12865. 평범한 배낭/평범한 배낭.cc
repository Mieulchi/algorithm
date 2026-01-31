#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[100001];
int ans;

void solve() {
    int w, v;
    for(int i = 0; i < n; ++i) {
        cin >> w >> v;
        for(int j = k; j >= w; --j) {
            dp[j] = max(dp[j], dp [j - w] + v);
            ans = max(ans, dp[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    
    solve();
    
    cout << ans;
}