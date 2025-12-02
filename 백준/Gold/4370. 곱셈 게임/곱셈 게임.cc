#include <iostream>
using namespace std;

int n;

void solve() {
    int player = 0;
    int l = 2, r = 9;
    while (true) {
        if (n >= l && n <= r) {
            break;
        }
        l = r + 1;
        r *= !player ? 2 : 9;
        player = ~player;
    }

    cout << (!player ? "Baekjoon wins." : "Donghyuk wins.") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> n) {

        solve();
    }

}