#include <iostream>
using namespace std;

int ans;

void solve() {
    int a1, a0;
    cin >> a1 >> a0;
    int c1, c2;
    cin >> c1 >> c2;
    int n;
    cin >> n;
    int op = a1 * n + a0;
    ans = op >= c1 * n && op <= c2 * n ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    cout << ans;
}