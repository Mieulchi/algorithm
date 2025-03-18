#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int ans;

void solve() {
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
		ans += sum;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		int sum = 0;
		int s;
		for (int j = 0; j < k; j++) {
			cin >> s;
			sum += s;
		}
		arr[i] = sum;
	}
	solve();
	cout << ans;
}