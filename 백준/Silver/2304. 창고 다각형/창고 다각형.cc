#include <iostream>
#include <map>
using namespace std;

int n;

int x[1001];

int xmax;
int xmin = 1001;
int hmax;
int localmax;

int ans;

void solve() {
	int now = x[xmax];
	ans += hmax;
	for (int i = xmax; i > localmax; i--) {
		if (x[i] <= now) {
			ans += now;
		}
		else {
			now = x[i];
			ans += now;
		}
	}
	now = x[xmin];
	for (int i = xmin; i < localmax; i++) {
		if (x[i] <= now) {
			ans += now;
		}
		else {
			now = x[i];
			ans += now;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int l, h;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		x[l] = h;
		if (l > xmax) {
			xmax = l;
		}
		if (l < xmin) {
			xmin = l;
		}
		if (h > hmax) {
			hmax = h;
			localmax = l;
		}
	}

	solve();

	cout << ans;
}