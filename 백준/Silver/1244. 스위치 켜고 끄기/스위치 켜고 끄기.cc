#include <iostream>
using namespace std;

int n;
int swich[101];

void solve() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int sx, given;
		cin >> sx >> given;
		if (sx == 1) {
			for (int i = given; i <= n; i += given) {
				swich[i] = swich[i] ? 0 : 1;
			}
		}
		else {
			int i = 0;
			while (given + i <= n && given - i >= 1) {
				if (swich[given + i] == swich[given - i]) {
						swich[given + i] = swich[given + i] ? 0 : 1;
						swich[given - i] = swich[given + i];
				}
				else {
					break;
				}
				i++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> swich[i];
	}
	solve();

	for (int i = 1; i <= n; i++) {
		cout << swich[i] << ' ';
		if (i != 0 && i % 20 == 0) {
			cout << '\n';
		}
	}
}