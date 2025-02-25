#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t, p;
int n, m;
int pi[1000001];
vector<int> v;

void solve() {
	n = t.length();
	m = p.length();
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && t[i] != p[j]) {
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			if (j == m - 1) {
				v.push_back(i - m + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, t);
	getline(cin, p);

	solve();

	cout << v.size() << '\n';
	for (int i : v) {
		cout << i << ' ';
	}
}