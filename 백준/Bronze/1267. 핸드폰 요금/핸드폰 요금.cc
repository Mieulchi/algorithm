#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[20];
int n;

void solve() {
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		ans1 += (arr[i] / 30 + 1) * 10;
		ans2 += (arr[i] / 60 + 1) * 15;
	}
	if (ans1 < ans2) {
		cout << 'Y' << ' ' << ans1;
	}
	else if (ans1 > ans2) {
		cout << 'M' << ' ' << ans2;
	}
	else {
		cout << 'Y' << ' ' << 'M' << ' ' << ans1;
	}
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve();
}