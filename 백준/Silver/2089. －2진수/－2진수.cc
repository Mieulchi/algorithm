#include <iostream>
using namespace std;

string ans;

int abs(int i) {
    return i > 0 ? i : i * -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (!n) {
        ans = '0';
    }
    while (n) {
        ans += abs(n) % 2 ? '1' : '0';
        
        int prev = n;
        n /= -2;
        if (n * -2 > prev) {
            n++;
        }
    }

    for (int i = ans.length() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}