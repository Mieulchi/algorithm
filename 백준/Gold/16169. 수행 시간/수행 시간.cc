#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef pair<int, int> pp;
vector<int> v[101];

int n, level, ans;
pp arr[101];

//O(N^3)

int startTime[101];

void solve() {
	
	for (int i = 0; i < v[1].size(); ++i) {
		startTime[v[1][i]] = arr[v[1][i]].second;
	}

	for (int i = 2; i <= level; ++i) {

		//계급 i인 컴퓨터가 켜지는 최소 시각을 기록
		for (int j = 0; j < v[i].size(); ++j) {
			int next = v[i][j];
			for (int k = 0; k < v[i - 1].size(); ++k) {
				int now = v[i - 1][k];
				startTime[next] = max(startTime[next], startTime[now] + (next - now) * (next - now));
			}
			startTime[next] += arr[next].second;
		}
	}

	for (int i = 0; i < v[level].size(); ++i) {
		ans = max(ans, startTime[v[level][i]]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		level = max(level, arr[i].first);
		v[arr[i].first].push_back(i);
	}

	solve();

	cout << ans;

}