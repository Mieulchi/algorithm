#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

string a, b, c, ans;
set<char> exist;
vector<char> v;
map<char, int> m;
int check[10];

long long calc(string s) {
	long long ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret += m[s[i]];
		ret *= 10;
	}
	return ret;
}

void recursive(int idx, int cnt) {
	if (cnt == v.size()) {
		long long ca, cb, cc;
		ca = calc(a);
		cb = calc(b);
		cc = calc(c);
		if (ca + cb == cc) {
			ans = "YES";
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!check[i]) {
				m[v[idx]]= i;
				check[i] = 1;
				recursive(idx + 1, cnt + 1);
				check[i] = 0;
				m[v[idx]] = -1;
			}
		}
	}
}

void solve() {
	ans = "NO";
	for (int i = 0; i < a.length(); i++) {
		exist.insert(a[i]);
	}
	for (int i = 0; i < b.length(); i++) {
		exist.insert(b[i]);
	}
	for (int i = 0; i < c.length(); i++) {
		exist.insert(c[i]);
	}

	for (auto it = exist.begin(); it != exist.end(); it++) {
		v.push_back(*it);
	}

	for (int i = 0; i < 10; i++) {
		m[v[0]] = i;
		check[i] = 1;
		recursive(1, 1);
		check[i] = 0;
		m[v[0]] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	solve();
	cout << ans;
}