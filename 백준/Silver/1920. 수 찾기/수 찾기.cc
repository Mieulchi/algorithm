#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
int ans;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (binary_search(arr, arr + n, t)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}