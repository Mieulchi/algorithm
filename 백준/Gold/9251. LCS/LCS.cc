#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[1001][1001];
int ans;

void solve() {
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    ans = dp[s1.length()][s2.length()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> s1 >> s2;
    solve();
    cout << ans;
    
}