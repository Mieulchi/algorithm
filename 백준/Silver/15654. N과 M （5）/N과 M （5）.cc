#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int arr[9];

void print(vector<int> v, int cnt) {
	if (cnt == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << arr[v[i]] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			vector<int> tmp = v;
			if (find(v.begin(), v.end(), i) == v.end()) {
				tmp.push_back(i);
				print(tmp, cnt - 1);
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		vector<int> v;
		v.push_back(i);
		print(v, m - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve();
}
