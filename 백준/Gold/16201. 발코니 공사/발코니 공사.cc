#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long r, c, k;
map<int, vector<int>> m;
long long ansCase = 1;
long long ansTile;

long long pow(long long base, long long ex) {
	long long ret = 1;
	while (ex) {
		if (ex & 1) {
			ret *= base;
			ret %= MOD;
		}
		base = (base * base) % MOD;

		ex >>= 1;
	}
	return ret;
}

void solve() {
	long long cnt = r;
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (!m[a].size()) {
			--cnt;
		}
		m[a].push_back(b);
	}
	if (c % 2) {
		ansCase = pow(c / 2 + 1, cnt);
	}
	ansTile += cnt * (c / 2);

	for (auto it = m.begin(); it != m.end(); ++it) {
		vector<int>& v = it->second;
		v.push_back(c + 1);
		sort(v.begin(), v.end());

		long long prev = 1;
		long long mul = 1;
		for (int i = 0; i < v.size(); ++i) {
			long long usableTile = v[i] - prev;
			if (usableTile > 1) {
				if (usableTile % 2) {
					mul *= (usableTile / 2 + 1);
				}
				mul %= MOD;
				ansTile += usableTile / 2;
			}
			prev = 1LL + v[i];
		}
		ansCase *= mul;
		ansCase %= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	solve();
	cout << ansTile << ' ' << ansCase;
}