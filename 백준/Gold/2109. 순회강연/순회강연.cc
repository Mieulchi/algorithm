#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, ans;

typedef pair<int, int> pp;

pp arr[10001];


bool cmp2(pp p1, pp p2) {
	if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	return p1.second > p2.second;
}


void solve() {
	priority_queue<int> pq;

	sort(arr + 1, arr + n + 1, cmp2);

	int last = arr[1].second;

	int idx = 1;
	for (int i = last; i >= 1; --i) {
		while (idx <= n && arr[idx].second >= i) {
			pq.push(arr[idx++].first);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	solve();

	cout << ans;
}