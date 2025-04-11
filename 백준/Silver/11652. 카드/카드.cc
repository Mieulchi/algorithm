#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map<long long, int> m;
long long ans;
long long maxn;
int maxc;

void solve() {
	long long t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		m[t]++;
		if (m[t] > maxc) {
			maxc = m[t];
			maxn = t;
		}
		else if (m[t] == maxc) {
			if (t < maxn) {
				maxn = t;
			}
		}
	}
	ans = maxn;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}