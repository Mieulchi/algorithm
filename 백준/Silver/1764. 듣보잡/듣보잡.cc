#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
map<string, int> dut;
vector<string> dutbo;

void solve() {
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		dut[s] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (dut[s]) {
			dutbo.push_back(s);
		}
	}

	cout << dutbo.size() << '\n';
	sort(dutbo.begin(), dutbo.end());
	for (int i = 0; i < dutbo.size(); i++) {
		cout << dutbo[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();
}