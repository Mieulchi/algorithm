#include <iostream>
#include <algorithm>
using namespace std;

int n, a, d;
int arr[20000];
int ans;

void solve() {
	int find = a;

	for (int i = 0; i < n; ++i) {
		if (arr[i] == find) {
			ans++;
			find += d;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> a >> d;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	solve();

	cout << ans;
 }
