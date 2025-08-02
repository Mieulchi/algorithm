#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans;

long long cnt(int target, long long div) {
    int o = div;
    long long ret = 0;
    while (div <= target) {
        ret += target / div;
        div *= o;
    }
    return ret;
}

void solve() {
    long long a, b, c, d, e, f;
    a = cnt(n, 5);
    b = cnt(n, 2);
    c = cnt(n - m, 5);
    d = cnt(n - m, 2);
    e = cnt(m, 5);
    f = cnt(m, 2);
    ans = min(a - c - e, b - d - f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    solve();
    cout << ans;
}   