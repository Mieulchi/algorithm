#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[8];
int check[8];

void recursive(vector<int> v, int k, int cnt) {
	v.push_back(arr[k]);
	if (!cnt) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (i == 0 || arr[i] != arr[i - 1] || check[i - 1]) {
				check[i] = 1;
				recursive(v, i, cnt - 1);
				check[i] = 0;
			}
		}
	}
	check[k] = 0;
}

void solve() {
	for (int i = 0; i < n; i++) {
		vector<int> v;
		if (i == 0 || arr[i] != arr[i - 1]) {
			check[i] = 1;
			recursive(v, i, m - 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	solve();
}