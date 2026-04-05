#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;

int lion[1000];
vector<int> v;
int maxL, minL = 2147483647, maxIdx, minIdx;

void solve() {
	sort(v.begin(), v.end());

	int mx = v[v.size() - 1];
	int mn = v[0];

	int costMax = min({ abs(lion[0] - mx), abs(lion[k - 1] - mx), abs(mx - maxL) * 2 });

	if (mx >= minL && mx <= maxL) {
		costMax = 0;
	}

	int costMin = min({ abs(lion[0] - mn), abs(lion[k - 1] - mn), abs(mn - minL) * 2 });

	if (mn >= minL && mn <= maxL) {
		costMin = 0;
	}

	ans += costMax + costMin;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int a;
	for (int i = 0; i < k; ++i) {
		cin >> lion[i];
		if (lion[i] > maxL) {
			maxL = lion[i];
			maxIdx = i;
		}

		if (lion[i] < minL) {
			minL= lion[i];
			minIdx = i;
		}

		if (i) {
			ans += abs(lion[i] - lion[i - 1]);
		}
	}
	for (int i = 0; i < n - k; ++i) {
		cin >> a;
		v.push_back(a);
	}

	solve();

	cout << ans;
}