#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> mx;
map<int, int> my;
map<int, int> checkx;
map<int, int> checky;
int ans;

void solve() {
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (!mx[x]) {
			mx[x] = 1;
		}
		else {
			if (!checkx[x]) {
				checkx[x] = 1;
				ans++;
			}
		}
		if (!my[y]) {
			my[y] = 1;
		}
		else {
			if (!checky[y]) {
				checky[y] = 1;
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}