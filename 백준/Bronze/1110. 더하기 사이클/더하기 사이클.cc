#include <iostream>
using namespace std;

int n;
int ans;

void solve() {
    int cpy = n;
    int tmp = 0;
    
    while (true) {
        tmp = cpy / 10 + cpy % 10;
        cpy = (cpy % 10 * 10) + tmp % 10;
        ans++;
        if (cpy == n) {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve();

    cout << ans;
}