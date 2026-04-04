#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, k;
string s, ans;

void solve() {
    for (int i = k - 1; i < s.length(); ++i) {
        ans += s[i];
    }
    if ((n - k) % 2) {
        for (int i = 0; i < k - 1; ++i) {
            ans += s[i];
        }
    }
    else {
        for (int i = k - 2; i >= 0; --i) {
            ans += s[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> s;

    solve();

    cout << ans;
}