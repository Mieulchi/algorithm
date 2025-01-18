#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500002];
int cmp[500002];
int ans;

void solve() {
    ans = 1;
    for (int i = n; i >= 1; i--) {
        int idx = (upper_bound(cmp + 1, cmp + n + 1, arr[i])) - (cmp + 1);
        if (i - idx + 1 > ans) {
            ans = i - idx + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cmp[i] = arr[i];
    }
    sort(cmp + 1, cmp + n + 1);

    solve();

    cout << ans << '\n';
}