#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;
    int ans = 0;
    while (n > 0 && m > 0) {
        n--;
        swap(n, m);
        ans++;
    }
    cout << ans - 1;
}