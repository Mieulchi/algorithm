#include <iostream>
#include <set>
#include <vector>
using namespace std;

string a, b, c, ans;
set<char> exist;
vector<pair<char, int>> v;
int check[10];

long long calc(string s) {
	long long ret = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first == s[i]) {
				ret += v[j].second;
				break;
			}
		}
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
			if (ans == "YES") {
				break;
			}
			if (!check[i]) {
				v[idx].second = i;
				check[i] = 1;
				recursive(idx + 1, cnt + 1);
				check[i] = 0;
				v[idx].second = -1;
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
		v.push_back({ *it, -1 });
	}

	for (int i = 0; i < 10; i++) {
		v[0].second = i;
		check[i] = 1;
		recursive(1, 1);
		check[i] = 0;
		v[0].second = -1;
		if (ans == "YES") {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	solve();
	cout << ans;
}