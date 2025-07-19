#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[50][50];
int ans;

void solve() {
    ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = arr[i][j];
            for (int k = 1; k <= min(n - i - 1, m - j - 1); k++) {
                if (arr[i + k][j] == t && arr[i][j + k] == t && arr[i + k][j + k] == t) {
                    if ((k + 1) * (k + 1) > ans) {
                        ans = (k + 1) * (k + 1);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    solve();
    cout << ans;
}