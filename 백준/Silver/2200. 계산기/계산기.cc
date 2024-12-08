#include <iostream>
#include <string>
using namespace std;

int n;

void solve() {
    int ans = 1;
    int min = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (i == 0) {
            continue;
        }
        if (s == "0") {
            ans += 2;
        }
        else {
            //+
            ans++;
            //숫자길이
            ans += s.length();
            // * x
            ans += 2;
        }
    }
    string s;
    cin >> s;
    if (s != "0") {
        ans += s.length();
        ans += 2;
    }
    else {
        ans++;
    }
    cout << ans;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;

    solve();
}
