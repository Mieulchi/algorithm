#include <iostream>
#include <queue>
using namespace std;

int n;
int ans;

void solve() {
	int k;
	cin >> k;
	int prev = k;
	int cache = 1;
	int mem = 0;
	for (int i = 1; i < n; i++) {
		cin >> k;
		if (k == prev) {
			cache++;
		}
		else {
			if (mem + cache > ans) {
				ans = mem + cache;
			}
			mem = cache;
			cache = 1;
			prev = k;
		}
	}
	if (mem + cache > ans) {
		ans = mem + cache;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}