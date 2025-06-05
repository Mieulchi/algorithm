#include <iostream>
using namespace std;

int p, t, n;
int arr[10000][80];
int sizes[10000];

void solve() {
	arr[0][0] = 1;
	sizes[0] = 1;
	for (int i = 1; i < 10000; i++) {
		for (int j = 0; j < sizes[i - 1]; j++) {
			arr[i][j] = arr[i - 1][j];
		}

		int cnt = 1;
		int j;
		for (j = 0; j < sizes[i - 1]; j++) {
			if (arr[i][j] > 0) {
				cnt++;
				arr[i][j]--;
			}
			else {
				arr[i][j] = cnt;
				sizes[i] = sizes[i - 1];
				cnt = 0;
				break;
			}
		}
		if (cnt) {
			arr[i][j] = cnt;
			if (sizes[i - 1] + 1 > 80) {
				break;
			}
			sizes[i] = sizes[i - 1] + 1;
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
		cout << t << ' ' << sizes[n - 1];
		for (int i = 0; i < sizes[n - 1]; i++) {
			if (i % 10 == 0) {
				cout << '\n';
			}
			cout << arr[n - 1][i] << ' ';
		}
		cout << '\n';
	}
}
