#include <iostream>
#include <vector>
using namespace std;

int n, l, m, ans;
pair<int, int> fish[100];
vector<int> rows;
vector<int> cols;

void solve() {
	l /= 2;
	for (int i = 1; i < l; i++) {
		int w = i, h = l - i;
		for (int i = 0; i < rows.size(); i++) {
			for (int j = 0; j < cols.size(); j++) {
				int r = rows[i];
				int c = cols[j];
				int cnt = 0;
				for (int k = 0; k < m; k++) {
					int r1 = fish[k].first;
					int c1 = fish[k].second;
					if (r1 >= r && r1 <= r + h && c1 >= c && c1 <= c + w) {
						cnt++;
					}
				}
				if (cnt > ans) {
					ans = cnt;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> m;
	rows.push_back(1);
	cols.push_back(1);
	for (int i = 0; i < m; i++) {
		cin >> fish[i].first >> fish[i].second;
		rows.push_back(fish[i].first);
		cols.push_back(fish[i].second);
	}
	solve();
	cout << ans;
}