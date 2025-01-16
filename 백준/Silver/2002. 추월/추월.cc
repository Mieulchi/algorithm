#include <iostream>
#include <map>
using namespace std;

int n;
string daegun[1000];
map<string, int> m;
int ans;

void solve() {
	int point = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == daegun[point]) {
			point++;
			while (m[daegun[point]]) {
				point++;
			}
		}
		else {
			if (!m[s]) {
				ans++;
				m[s] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> daegun[i];
	}

	solve();

	cout << ans;
}