#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int m, n;
int arr[1000001];

void solve() {
	for (int i = m; i <= n; i++) {
		if (!arr[i]) {
			cout << i << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	arr[1] = 1;
	for (int i = 2; i < 500001; i++) {
		if (arr[i]) {
			continue;
		}
		else {
			for (int j = i + i; j < 1000001; j += i) {
				arr[j] = 1;
			}
		}
	}

	cin >> m >> n;

	solve();
}