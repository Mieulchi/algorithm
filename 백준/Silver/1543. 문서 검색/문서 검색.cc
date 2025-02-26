#include <iostream>
#include <string>
using namespace std;

string t, p;
int n, m;
int ans;
void solve() {
	n = t.length();
	m = p.length();
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < m; j++) {
			if (t[i + j] != p[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			ans++;
			i += m - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, t);
	getline(cin, p);
	solve();
	cout << ans;
}