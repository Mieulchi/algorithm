#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string ans;

void solve() {
	string s;
	cin >> s;
	ans = "";

	vector<int> v;
	int i;
	int cmp = s[s.length() - 1] - '0';
	v.push_back(cmp);
	for (i = s.length() - 2; i >= 0; i--) {
		if (cmp <= s[i] - '0') {
			v.push_back(s[i] - '0');
			cmp = s[i] - '0';
		}
		else {
			break;
		}
	}
	if (s.size() == v.size()) {
		ans = "BIGGEST";
	}
	else {
		sort(v.begin(), v.end());
		for (int j = 0; j < i; j++) {
			ans += s[j];
		}
		int t;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] > s[i] - '0') {
				t = v[j];
				v[j] = s[i] - '0';
				break;
			}
		}
		ans += t + '0';
		for (int j = 0; j < v.size(); j++) {
			ans += v[j] + '0';
		}
	}
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		solve();

		cout << ans << '\n';
	}
}