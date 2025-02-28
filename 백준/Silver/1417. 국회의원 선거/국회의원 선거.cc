#include <iostream>
using namespace std;

int n;
int arr[50];
int ans;

void solve() {
	while (true) {
		int max = arr[0];
		int index = 0;
		int flag = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] >= max) {
				flag = 0;
				max = arr[i];
				index = i;
			}
		}
		if (flag) {
			break;
		}
		else {
			arr[index]--;
			arr[0]++;
			ans++;
		}
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
	cout << ans;
}