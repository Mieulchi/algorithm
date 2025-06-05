#include <iostream>
#include <vector>
using namespace std;

int p, t, n;
vector<int> arr[10000];

void solve() {
	arr[0].push_back(1);
	for (int i = 1; i < 10000; i++) {
		arr[i] = arr[i - 1];

		int cnt = 1;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] > 0) {
				cnt++;
				arr[i][j]--;
			}
			else {
				arr[i][j] = cnt;
				cnt = 0;
				break;
			}
		}
		if (cnt) {
			arr[i].push_back(cnt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();

	cin >> p;
	while (p--) {
		cin >> t >> n;
		cout << t << ' ' << arr[n - 1].size();
		for (int i = 0; i < arr[n - 1].size(); i++) {
			if (i % 10 == 0) {
				cout << '\n';
			}
			cout << arr[n - 1][i] << ' ';
		}
		cout << '\n';
	}
}
