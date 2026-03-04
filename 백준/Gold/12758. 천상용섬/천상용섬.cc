#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007
#define MAX 1000000
typedef long long ll;
typedef pair<int, int> pp;

int n;
int arr[301];
int ans;
vector<int> v[1000001];
vector<pair<int, int>> dp[301];

void preprocess() {
	for (int i = 1; i <= MAX; ++i) {
		for (int j = i; j <= MAX; j += i) {
			v[j].push_back(i);
		}
	}
}

bool cmp(pp p1, pp p2) {
	return p1.first < p2.first;
}

void init() {
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i].clear();
	}
}

void solve() {

	init();

	for (int i = 0; i < v[arr[1]].size(); ++i) {
		dp[1].push_back({ v[arr[1]][i], i + 1 });
	}

	for (int i = 2; i <= n; ++i) {

		ll sum = 0;
		for (int j = 0; j < v[arr[i]].size(); ++j) {

			//i - 1번째 배열에서 현재 약수와 동일한 위치
			int idx = upper_bound(v[arr[i - 1]].begin(), v[arr[i - 1]].end(), v[arr[i]][j]) - v[arr[i - 1]].begin();
			if (idx - 1 >= 0) {
				sum += dp[i - 1][idx - 1].second;
				sum %= MOD;
			}

			dp[i].push_back({ v[arr[i]][j], sum });
		}
	}


	ans = dp[n][v[arr[n]].size() - 1].second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	preprocess();
	
	int t;
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}

		solve();

		cout << ans <<'\n';
	}	
}