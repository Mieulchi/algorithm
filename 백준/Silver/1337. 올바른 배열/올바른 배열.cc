#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[50];
int ans;

void solve() {
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int p = i + 1;
		while (p < n) {
			if (arr[p++] < arr[i] + 5) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt > ans) {
			ans = cnt;
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
	cout << 5 - ans;
}