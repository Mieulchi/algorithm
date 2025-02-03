#include <iostream>
#include <vector>
using namespace std;

int n, m;

void solve(vector<int> v, int a, int cnt) {
	vector<int> tmp = v;
	if (cnt == 0) {
		tmp.push_back(a);
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	tmp.push_back(a);
	for (int i = a; i <= n - cnt; i++) {
		solve(tmp, i + 1, cnt - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n - m + 1; i++) {
		vector<int> v;
		solve(v, i, m - 1);
	}
}