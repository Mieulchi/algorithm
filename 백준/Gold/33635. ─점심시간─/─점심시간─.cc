#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;

int n, m, q, ans;
unordered_map<string, int> genre;
bitset<200> book[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    string s, b;
    for (int i = 0; i < n; i++) {
        cin >> s;
        genre[s] = i;
    }

    cin >> m;
    int cnt;
    for (int i = 0; i < m; i++) {
        cin >> cnt;
        cin >> b;
        bitset<200> tmp;
        while (cnt--) {
            cin >> s;
            tmp[genre[s]] = 1;
        }
        book[i] = tmp;
    }
    
    cin >> q;
    while (q--) {
        ans = 0;
        cin >> cnt;
        bitset<200> tmp;
        while (cnt--) {
            cin >> s;
            tmp[genre[s]] = 1;
        }
        for (int i = 0; i < m; i++) {
            if ((book[i] & tmp) == tmp) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
