#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1e9

typedef long long ll;
typedef pair<pair<int, int>, pair<int, int>> ppp;

int n;
ppp arr[101];
//높이, 이전 인덱스
pair<int, int> dp[101];
int mem[101];

int ans, idx;
vector<int> v;

bool cmp(ppp p1, ppp p2) {
	return p1.first.second > p2.first.second;
}

void solve() {
	sort(arr + 1, arr + n + 1, cmp);

	dp[1] = { arr[1].second.first, 1 };
	ans = dp[1].first;
	idx = 1;
	for (int i = 2; i <= n; ++i) {
		int nowH = arr[i].second.first;
		int nowW = arr[i].second.second;

		dp[i] = { arr[i].second.first, i };

		for (int j = 1; j < i; ++j) {
			int prevW = arr[j].second.second;
			int prevH = dp[j].first;

			if (prevW > nowW) {
				if (prevH + nowH > dp[i].first) {
					dp[i].first = prevH + nowH;
					dp[i].second = j;
				}
			}
		}
		if (dp[i].first > ans) {
			ans = dp[i].first;
			idx = i;
		}
	}

	v.push_back(arr[idx].first.first);
	while (true) {
		if (idx == dp[idx].second) {
			break;
		}
		v.push_back(arr[dp[idx].second].first.first);
		idx = dp[idx].second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
		arr[i].first.first = i;
	}

	solve();

	cout << v.size() << '\n';
	for (int i : v) {
		cout << i << '\n';
	}
}
