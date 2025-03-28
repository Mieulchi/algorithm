#include <iostream>
#include <string>
using namespace std;

string s;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    int i = 0;
    while (i < s.length()) {
        if (s[i] != ' ') {
            ans++;
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
        }
        i++;
    }

    cout << ans;
}