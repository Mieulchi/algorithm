#include <iostream>
#include <map>
using namespace std;

int n, ans;
map<string, int> m;

void solve() {
	string s;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> s >> c;
		if (c == '+') {
			m[s]++;
			ans++;
		}
		else {
			if (m[s]) {
				m[s]--;
				ans--;
			}
			else {
				ans++;
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