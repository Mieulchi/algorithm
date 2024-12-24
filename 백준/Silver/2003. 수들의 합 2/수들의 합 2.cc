#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int ans;

int arr[10001];

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		long long sum = 0;
		int index = i;
		while (sum < m && index < n) {
			sum += arr[index++];
			if (sum == m) {
				ans++;
				break;
			}
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	            
	cin >> n >> m;

	solve();

	cout << ans;
}