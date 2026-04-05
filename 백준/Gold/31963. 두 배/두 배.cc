#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

int n;
ll arr[250000];
int ans;

void solve() {
	for (int i = 1; i < n; ++i) {
		while (arr[i] < arr[i - 1]) {
			arr[i] *= 2;
			++ans;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}