#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map<long long, int> m;
long long ans;

bool cmp(pair<long long, int> p1, pair<long long, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second > p2.second;
	}
}

void solve() {
	vector<pair<long long, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	ans = v[0].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	long long t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		m[t]++;
	}
	solve();
	cout << ans;
}