#include <iostream>
using namespace std;

int n;
int g, h;
int ans;

void solve() {
	int size = 2;
	ans = 1;
	while (size <= n) {
		int flag = 0;
		for (int i = 1; i <= n; i += size) {
			if ((i <= g && g < i + size) && (i <= h && h < i + size)) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			break;
		}

		size *= 2;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> g >> h;

	solve();

	cout << ans;
}