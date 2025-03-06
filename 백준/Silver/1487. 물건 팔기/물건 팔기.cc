#include <iostream>
using namespace std;

#define MAX 1000000000

int n;
pair<int, int> info[50];
int ans;

void solve() {
	ans = MAX;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int price = info[i].first;
		int profit = 0;
		for (int j = 0; j < n; j++) {
			if (info[j].first >= price && (price - info[j].second) > 0) {
				profit += (price - info[j].second);
			}
		}
		if (profit >= max && profit) {
			if (profit == max) {
				if (ans > price) {
					ans = price;
				}
				continue;
			}
			max = profit;
			ans = price;
		}
 	}
	if (ans == MAX) {
		ans = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i].first >> info[i].second;
	}
	solve();
	cout << ans;
}