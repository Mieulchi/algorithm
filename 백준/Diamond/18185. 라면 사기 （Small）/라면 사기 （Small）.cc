#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000];
long long ans;

void buy(int f, int t, int m) {
	for (int i = f; i < t; i++) {
		arr[i] -= m;
	}
	ans += m * ((t - f) * 2 + 1);
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (arr[i]) {
			if (i + 1 < n && arr[i + 1]) {
				if (i + 2 < n && arr[i + 2]) {
					if (arr[i + 2] <= arr[i]) {
						if (arr[i + 1] <= arr[i]) {
							buy(i, i + 3, min(arr[i + 1], arr[i + 2]));
						}
						else {
							buy(i, i + 2, max(1, arr[i] - arr[i + 2]));
						}
					}
					else {
						if (arr[i + 1] > arr[i + 2]) {
							buy(i, i + 2, min(arr[i], arr[i + 1] - arr[i + 2]));
						}
						else {
							buy(i, i + 3, min(arr[i], arr[i + 1]));
						}
					}
				}
				else {
					buy(i, i + 2, min(arr[i], arr[i + 1]));
				}
			}
			else {
				buy(i, i + 1, arr[i]);
			}
		}
		if (arr[i]) {
			i--;
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