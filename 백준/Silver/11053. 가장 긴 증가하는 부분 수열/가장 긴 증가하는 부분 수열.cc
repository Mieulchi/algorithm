#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int lis[1000];
int idx;

void solve() {
	lis[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > lis[idx]) {
			lis[++idx] = arr[i];
		}
		else {
			int tmpindex = lower_bound(lis, lis + idx, arr[i]) - lis;
			if (lis[tmpindex] > arr[i]) {
				lis[tmpindex] = arr[i];
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

	cout << idx + 1;
}