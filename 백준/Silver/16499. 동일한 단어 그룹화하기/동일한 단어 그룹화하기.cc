#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
map<string, int> m;
string s;
int ans;

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		if (!m[s]) {
			ans++;
		}
		m[s]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}