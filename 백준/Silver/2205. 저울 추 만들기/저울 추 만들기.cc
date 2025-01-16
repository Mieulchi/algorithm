#include <iostream>
using namespace std;

int n;
int power[14] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384 };
int ans[10001];

void solve() {
	int i = n;
	while (i) {
		int upper = 2;
		for (int j = 0; j < 14; j++) {
			if (i <= power[j]) {
				upper = power[j];
				break;
			}
		}
		if (i == upper) {
			ans[i] = upper;
			i--;
			continue;
		}
		for (int j = i; j >= upper - i; j--) {
			ans[j] = upper - j;
		}
		i = upper - i - 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	solve();

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}