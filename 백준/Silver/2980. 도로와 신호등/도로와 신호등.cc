#include <iostream>
using namespace std;

int n, l;
int ans;

void solve() {
	int d, r, g;

	int time = 0;
	int location = 0;
	for (int i = 0; i < n; i++) {
		cin >> d >> r >> g;
		time += d - location;
		location += d - location;
		int tmp = time;
		int tot = r + g;
		if (time > tot) {
			tmp = time - (time / tot) * tot;
		}
		if (r > tmp) {
			ans += r - tmp;
			time += r - tmp;
		}
	}
	ans += l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;

	solve();
	
	cout << ans;
}