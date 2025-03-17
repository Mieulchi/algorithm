#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];

void solve() {
	sort(arr, arr + n);

	int p = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] + 1 == arr[i]) {
			int j;
			for (j = i + 1; j < n; j++) {
				if (arr[j] != arr[i]) {
					break;
				}
			}
			if (j == n) {
				swap(arr[p], arr[i]);
				p = 0;
			}
			else {
				swap(arr[i], arr[j]);
			}
			i = 0;
		}
		else {
			if (arr[i - 1] != arr[i]) {
				p = i;
			}
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
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}