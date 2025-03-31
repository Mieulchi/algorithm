#include <iostream>
using namespace std;

#define MOD 1000000007

int n;
long long ans1;
int ans2;

void solve() {
    long long dp0 = 1;
    long long dp1 = 1;
    for (int i = 3; i <= n; i++) {
        ans1 = dp0 + dp1;
        dp0 = dp1;
        dp1 = ans1;
        dp0 %= MOD;
        dp1 %= MOD;
        ans1 %= MOD;
    }
    ans2 = n - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve();
    cout << ans1 << ' ' << ans2;
}