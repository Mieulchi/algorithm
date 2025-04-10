#include <iostream>
#include <algorithm>
using namespace std;

string s;
string ans;

bool cmp(char c1, char c2) {
    return c1 > c2;
}

void solve() {
    int flag = 0;
    int sum = 0;
    int idx = -1;
    int op;
    for(int i = 0; i < s.length(); i++) {
        op = s[i] - '0';
        if (!op && !flag) {
            flag = 1;
            idx = i;
        }
        sum += op;
    }
    if (sum % 3 != 0 || !flag) {
        ans = "-1";
    }
    else {
        ans = s;
        swap(ans[idx], ans[ans.length() - 1]);
        sort(ans.begin(), ans.end(), cmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    
    solve();
    
    cout << ans;
}