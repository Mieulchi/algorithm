#include <iostream>
#include <queue>
using namespace std;

int t;
pair<int, int> arr[4];
int ans;

void solve() {
	for (int i = 0; i < 4; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int diagonal = 0;
	int idx = 0;
	pair<int, int> vec1;
	for (int i = 1; i < 4; i++) {
		if ((arr[i].first - arr[0].first) * (arr[i].first - arr[0].first) + (arr[i].second - arr[0].second) * (arr[i].second - arr[0].second) > diagonal) {
			idx = i;
			vec1 = { arr[i].first - arr[0].first, arr[i].second - arr[0].second };
			diagonal = (arr[i].first - arr[0].first) * (arr[i].first - arr[0].first) + (arr[i].second - arr[0].second) * (arr[i].second - arr[0].second);
		}
	}
	int d1 = 0, d2 = 0;
	for (int i = 1; i < 4; i++) {
		if (i != idx) {
			if (!d1) {
				d1 = i;
			}
			else {
				d2 = i;
			}
		}
	}
	pair<int, int> vec2 = { arr[d1].first - arr[d2].first, arr[d1].second - arr[d2].second };
	int diagonal2 = (arr[d1].first - arr[d2].first) * (arr[d1].first - arr[d2].first) + (arr[d1].second - arr[d2].second) * (arr[d1].second - arr[d2].second);
	if (diagonal == diagonal2 && vec1.first * vec2.first + vec1.second * vec2.second == 0) {
		ans = 1;
	}
	else {
		ans = 0;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
		cout << ans << '\n';
	}
}