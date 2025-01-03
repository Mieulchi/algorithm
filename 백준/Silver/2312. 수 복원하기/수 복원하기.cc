#include <iostream>
using namespace std;

int n;

void solve() {
	int m;
	cin >> m;

	int i = 2;
	int count = 0;
	while (m >= 1) {
		if (m % i == 0) {
			m /= i;
			count++;
			continue;
		}
		else {
			if (count) {
				cout << i << " " << count << '\n';
			}
			count = 0;
			i++;
			if (m == 1) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		solve();
	}
}