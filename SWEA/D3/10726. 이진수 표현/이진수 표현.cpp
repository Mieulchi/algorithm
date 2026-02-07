#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n, m;

    string ans;

    for (int i = 1; i <= t; ++i) {
           
        cin >> n >> m;

        ans = "ON";
        for (int i = 0; i < n; ++i) {
            if (!((m >> i) & 1)) {
                ans = "OFF";
                break;
            }
        }

        cout << '#' << i << ' ' << ans << '\n';
    }
}