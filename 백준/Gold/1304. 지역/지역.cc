#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans;
vector<pair<int, int>> v;

void solve() {
	ans = n;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		if (a > b) {
			v.push_back({ a - 1, b - 1 });

			int size = a - b + 1;
			if (size > n / 2) {
				ans = 1;
				break;
			}
			while (true) {
				if (n % size == 0) {
					int flag = 1;
					for (int j = 0; j < v.size(); j++) {
						if (v[j].first / size != v[j].second / size) {
							flag = 0;
							break;
						}
					}
					if (flag) {
						ans = n / size;
						break;
					}
					else {
						size++;
					}
				}
				else {
					size++;
				}
				if (size > n / 2) {
					ans = n / size;
					break;
				}
			}
			if (ans == n) {
				break;
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << ans;
}