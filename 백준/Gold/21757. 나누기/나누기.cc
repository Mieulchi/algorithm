#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n;
int arr[100001];
long long sum[100001], ans;
map<long long, vector<int>> pos;

long long f(int l, int r, int t) {

	//
	if (pos.find(t) == pos.end()) {
		return 0;
	}
	const vector<int>& v = pos[t];
	int lower = lower_bound(v.begin(), v.end(), l) - v.begin();
	int upper = lower_bound(v.begin(), v.end(), r) - v.begin();

	return upper - lower;
}

void solve() {
	if (sum[n] % 4 == 0) {
		int t = sum[n] / 2;
		for (int i = 1; i <= n; ++i) {
			if (sum[i] == t) {
				if (i != 1 && i != n) {
					ans += f(1, i, sum[i] / 2) * f(i + 1, n, (sum[i] + sum[n]) / 2);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
		pos[sum[i]].push_back(i);
	}
 	solve();
	cout << ans;
}