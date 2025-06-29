#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;
map<int, pair<int, int>> m;
int level[250000];
set<int> s;
long long ans;

void insert(int root, int key) {
	auto it = s.lower_bound(key);
	int idx = *it;
	int prv = *prev(it);
	if (it == s.end()) {
		m[prv].second = key;
		s.insert(key);
		m[key] = { -1, -1 };
		level[key] = level[prv] + 1;
		ans += level[key];
	}
	else {
		if (m[idx].first == -1) {
			m[idx].first = key;
			s.insert(key);
			m[key] = { -1, -1 };
			level[key] = level[idx] + 1;
			ans += level[key];
		}
		else {
			m[prv].second = key;
			s.insert(key);
			m[key] = { -1, -1 };
			level[key] = level[prv] + 1;
			ans += level[key];
		}
	}
}

void solve() {
	int root;
	cin >> root;
	m[root] = { -1, -1 };
	level[root] = 1;
	s.insert(root);
	ans++;

	int tmp;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		insert(root, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}