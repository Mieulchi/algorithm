#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> m;

int ansi;
string ans;

void solve() {
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
        if (m[s] >= ansi) {
            if (m[s] == ansi) {
                if (s < ans) {
                    ans = s;
                }
            }
            else {
                ansi = m[s];
                ans = s;
            }
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