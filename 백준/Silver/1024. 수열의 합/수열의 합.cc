#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int arr[100];
int ans;

void solve() {
	for (int i = l; i <= 100; i++) {
		int op = n - i * (i + 1) / 2;
		if (op / i < -1) {
			break;
		}
		if (op % i == 0) {
			ans = i;
			for (int j = 0; j < ans; j++) {
				arr[j] = j + 1 + op / i;
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	solve();
	if (!ans) {
		cout << -1;
	}
	else {
		for (int i = 0; i < ans; i++) {
			cout << arr[i] << ' ';
		}
	}
}