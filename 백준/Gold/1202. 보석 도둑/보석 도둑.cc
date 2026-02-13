#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define pp pair<int, int>

int n, k;
pp boseok[300001];
int bags[300001];
long long ans;

bool cmp(pp p1, pp p2) {
	return p1.first < p2.first;
}

void solve() {
	sort(boseok, boseok + n, cmp);
	sort(bags, bags + k);

	priority_queue<int, vector<int>> pq;

	int idx = 0;
	for (int i = 0; i < k; ++i) {
		while (idx < n && boseok[idx].first <= bags[i]) {
			pq.push(boseok[idx++].second);

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

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> boseok[i].first >> boseok[i].second;
	}

	for (int i = 0; i < k; ++i) {
		cin >> bags[i];
	}
	solve();

	cout << ans;
}
