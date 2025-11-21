#include <iostream>
using namespace std;

int s, n, k, r1, r2, c1, c2;
long long mx = 1;

int f(int r, int c) {
    int f = n % 2 ? n / 2 - k / 2 : n / 2 - k / 2;
    int t = n % 2 ? n / 2 + k / 2 : n / 2 + k / 2 - 1;

    for (long long i = n; i <= mx; i *= n) {
        int tr = i == mx ? r % i : r / i;
        int tc = i == mx ? c % i : c / i;
        if (tr % n >= f && tr % n <= t && tc % n >= f && tc % n <= t) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout << f(i, j) ? 1 : 0;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    for (int i = 0; i < s; ++i) {
        mx *= n;
    }
    solve();
}