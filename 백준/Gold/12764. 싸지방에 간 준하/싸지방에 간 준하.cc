#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, cnt = 1;
pp arr[100001];
int ans[100001];

struct cmp {
	bool operator()(pp p1, pp p2) {
		return p1.first > p2.first;
	}
};

struct cmp2 {
	bool operator()(int i1, int i2) {
		return i1 > i2;
	}
};

void solve() {
	sort(arr, arr + n);

	priority_queue<pp, vector<pp>, cmp> started;

	priority_queue<int, vector<int>, cmp2> ended;

	started.push({ arr[0].second, 0 });
	ans[0]++;
	for (int i = 1; i < n; ++i) {
		int now = arr[i].first;
		int end = arr[i].second;

		while (!started.empty() && started.top().first < now) {
			ended.push(started.top().second);
			started.pop();
		}

		if (!ended.empty() && ended.top() < end) {
			int used = ended.top();
			started.push({ end, used });
			ans[used]++;
			ended.pop();
		}
		else {
			started.push({ end, cnt });
			ans[cnt++]++;
		}
	}
	cnt = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	solve();
	cout << cnt << '\n';
	for (int i = 0; i < cnt; ++i) {
		cout << ans[i] << ' ';
	}
}