#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000

int n, m;

void recursive(vector<int> v, int cnt) {
	if (!cnt) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		vector<int> tmp = v;
		if (find(v.begin(), v.end(), i) == v.end()) {
			tmp.push_back(i);
			recursive(tmp, cnt - 1);
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		v.push_back(i);
		recursive(v, m - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	solve();
}