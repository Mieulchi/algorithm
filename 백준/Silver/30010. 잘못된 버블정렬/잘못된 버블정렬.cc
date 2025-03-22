#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];

void solve() {
	arr[0] = 2;
	for (int i = 1; i < n; i++) {
		arr[i] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}