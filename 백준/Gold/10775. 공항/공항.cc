#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pp;
int arr[100001];

bool cmp(int i1, int i2) {
	return i1 > i2;
}

set<int, greater<int>> s;

int g, p, ans;

void solve() {
	int n;
	for (int i = 0; i < p; ++i) {
		auto it = s.lower_bound(arr[i]);
		if (it == s.end()) {
			break;
		}
		s.erase(it);
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g >> p;
	for (int i = 1; i <= g; ++i) {
		s.insert(i);
	}
	for (int i = 0; i < p; ++i) {
		cin >> arr[i];
	}
	solve();

	cout << ans;
}