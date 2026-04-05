#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int n, m;
map<string, int> mp;

void solve() {
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	string s;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		mp[s] = 1;
	}

	cin >> m;
	int cnt = 0;

	int least = n / 2 + n % 2;

	for (int i = 0; i < m; ++i) {
		cin >> s;
		if (mp[s]) {
			mp[s] = 0;
			cnt++;
		}
		if (cnt >= least) {
			cout << i + 1;
			break;
		}
	}
}