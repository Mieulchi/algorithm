#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long ans;

void solve() {
	long long level;
	if ((n > 0 && m > 0) || (n < 0 && m < 0)) {
		level = n + m;
		level = abs(level);
	}
	else {
		level = max(abs(n), abs(m));
	}
	ans = 1 + 6 * (level - 1) * level / 2;

	long long x = level - 1, y = 1;
	long long i;
	for (i = 1; i <= 6 * level; i++) {
		if (x == n && y == m) {
			break;
		}
		if (x > 0 && y > 0) {
			x--;
			y++;
		}
		else if (x <= 0 && y > 0) {
			if (x * -1 == level) {
				y--;
			}
			else {
				x--;
			}
		}
		else if (x < 0 && y <= 0) {
			y--;
			x++;
		}
		else if (x >= 0 && y < 0) {
			if (x == level) {
				y++;
			}
			else {
				x++;
			}
		}
	}
	ans += i;
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;

	if (n == 0 && m == 0) {
		ans = 1;
	}
	else {
		solve();
	}

	cout << ans << '\n';
	
}