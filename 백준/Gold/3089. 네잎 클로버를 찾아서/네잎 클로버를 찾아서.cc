#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> x[200001];
vector<int> y[200001];
string orders;
int px, py;

void solve() {
	for (int i = 0; i < 200001; i++) {
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
	}

	px = 0, py = 0;
	for (int i = 0; i < m; i++) {
		char order = orders[i];
		if (order == 'U') {
			int idx = upper_bound(x[px + 100000].begin(), x[px + 100000].end(), py) - x[px + 100000].begin();
			py = x[px + 100000][idx];
		}
		else if (order == 'D') {
			int idx = lower_bound(x[px + 100000].begin(), x[px + 100000].end(), py) - x[px + 100000].begin();
			py = x[px + 100000][idx - 1];
		}
		else if (order == 'R') {
			int idx = upper_bound(y[py + 100000].begin(), y[py + 100000].end(), px) - y[py + 100000].begin();
			px= y[py + 100000][idx];
		}
		else { //L
			int idx = lower_bound(y[py + 100000].begin(), y[py + 100000].end(), px) - y[py + 100000].begin();
			px = y[py + 100000][idx - 1];
		}
	}

 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x[a + 100000].push_back(b);
		y[b + 100000].push_back(a);
	}
	cin >> orders;
	solve();
	cout << px << ' ' << py;
}
