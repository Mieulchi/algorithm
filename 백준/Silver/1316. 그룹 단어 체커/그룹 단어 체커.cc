#include <iostream>
#include <map>

using namespace std;

int n;
int ans;

void solve() {
    string s;
   for (int i = 0; i < n; i++) {
       cin>>s;
       short c[26] = { 0 };
       c[s[0] - 'a'] = 1;
       int flag = 1;
       for(int j=1; j<s.length(); j++) {
           if (s[j] != s[j - 1]) {
               if (c[s[j] - 'a']) {
                   flag = 0;
                   break;
               }
               c[s[j] - 'a'] = 1;
           }
       }
       if (flag) {
           ans++;
       }
   }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

    cout<<ans;
}