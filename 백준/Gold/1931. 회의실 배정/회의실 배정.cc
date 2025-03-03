#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> meeting[100001];
int ans;

bool cmp(pair<int, int> m1, pair<int, int> m2) {
	if (m1.second != m2.second) {
		return m1.second < m2.second;
	}
	else {
		return m1.first < m2.first;
	}
}

void solve() {
	int end = meeting[0].second;
	ans = 1;
	for (int i = 1; i < n; i++) {
		if (meeting[i].first >= end) {
			end = meeting[i].second;
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> meeting[i].first >> meeting[i].second;
	}
	sort(meeting, meeting + n, cmp);
	solve();
	cout << ans;
}