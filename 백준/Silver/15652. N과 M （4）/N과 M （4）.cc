#include <iostream>
#include <vector>
using namespace std;

int n, m;

void recursive(vector<int> v, int j, int cnt) {
	v.push_back(j);
	if (cnt == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = j; i <= n; i++) {
			recursive(v, i, cnt - 1);
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		recursive(v, i, m - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();
}