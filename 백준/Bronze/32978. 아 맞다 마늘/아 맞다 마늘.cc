#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> m;
string ans;

void solve() {
	string s;
	for (int i = 0; i < n - 1;i++) {
		cin >> s;
		m[s] = 0;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second) {
			ans = it->first;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s] = 1;
	}
	solve();
	cout << ans;
}