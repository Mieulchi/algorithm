#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s[1000];

int ans;
vector<string> v;

void solve() {
	int len = s[0].length();
	for (int i = 0; i < len; i++) {
		int flag = 1;
		for (int j = 0; j < n; j++) {
			string key = s[j].substr(len - 1 - i, len);
			if (find(v.begin(), v.end(), key) != v.end()) {
				flag = 0;
				break;
			}
			v.push_back(key);
		}
		if (flag) {
			ans = i + 1;
			break;
		}
		v.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	solve();

	cout << ans;
}