#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans;

void solve() {
    int i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) {
            ans = n - (n / i);
            break;
        }
        else {
            i++;
        }
    }
    if (!ans) {
        ans = n - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n != 1) {
        solve();
    }

    cout << ans << '\n';
}