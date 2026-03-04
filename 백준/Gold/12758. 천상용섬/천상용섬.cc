#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pp;

int n;
int arr[301];
int ans;
vector<int> v[301];
int dp[301][300];

void solve() {

	ans = 0;

	for (int i = 1; i <= n; ++i) {
		v[i].clear();

		int limit = sqrt(arr[i]);

		for (int j = 1; j <= limit; ++j) {
			if (arr[i] % j == 0) {
				v[i].push_back(j);
			}
		}

		int temp = v[i].size() - 1;
		if (v[i].back() * v[i].back() == arr[i]) temp--;

		for (; temp >= 0; temp--) {
			v[i].push_back(arr[i] / v[i][temp]);
		}
	}

	for (int i = 0; i < v[1].size(); ++i) {
		dp[1][i] = i + 1;
	}

	for (int i = 2; i <= n; ++i) {

		ll sum = 0;
		for (int j = 0; j < v[i].size(); ++j) {

			//i - 1번째 배열에서 현재 약수와 동일한 위치
			int idx = upper_bound(v[i - 1].begin(), v[i - 1].end(), v[i][j]) - v[i - 1].begin();
			if (idx - 1 >= 0) {
				sum += dp[i - 1][idx - 1];
				sum %= MOD;
			}

			dp[i][j] = sum;
		}
	}

	ans = dp[n][v[n].size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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