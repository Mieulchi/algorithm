#include <iostream>
#include <array>
using namespace std;

#define MOD 1000000007

int n;
array<long long, 5> dp = { 1,0,0,0,0 };

void solve() {
    for (int i = 0; i < n; ++i) {
        array<long long, 5> arr{};

        arr[0] = (25 * dp[0]) % MOD;
        arr[1] = (25 * dp[1] + dp[0]) % MOD;
        arr[2] = (25 * dp[2] + dp[1]) % MOD;
        arr[3] = (25 * dp[3] + dp[2]) % MOD;
        arr[4] = (26 * dp[4] + dp[3]) % MOD;
        
        dp = arr;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve();
    cout << dp[4];

}