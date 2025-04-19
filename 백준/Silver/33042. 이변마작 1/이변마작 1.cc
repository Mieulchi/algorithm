#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> m;
int ans;

void solve() {
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s]++;
		if (m[s] > 4) {
			ans = i + 1;
			break;
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