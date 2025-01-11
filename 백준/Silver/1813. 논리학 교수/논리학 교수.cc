#include <iostream>
using namespace std;

int n;
int arr[51];

void solve() {
	int i;
	for (i = 50; i >= 0; i--) {
		if (i == arr[i]) {
			break;
		}
	}

	cout << i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	solve();
}