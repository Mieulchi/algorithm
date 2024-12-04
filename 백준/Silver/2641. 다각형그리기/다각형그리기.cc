#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
int rarr[50];

int arr2[100][50];

int n, k;
int ans[100];
int num;

void solve() {
	for (int i = 0; i < k; i++) {

		int flag = 1;
		for (int j = 0; j < n; j++) {
			flag = 1;

			int count = 0;
			int l = j;
			while (count < n) {
				if (arr[count] != arr2[i][l]) {
					flag = 0;
					break;
				}
				l++;
				count++;
				if (l >= n) {
					l %= n;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			for (int j = 0; j < n; j++) {
				flag = 1;

				int count = 0;
				int l = j;
				while (count < n) {
					if (rarr[count] != arr2[i][l]) {
						flag = 0;
						break;
					}
					l++;
					count++;
					if (l >= n) {
						l %= n;
					}
				}
				if (flag) {
					break;
				}
			}
		}

		if (flag) {
			num++;
			ans[i] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] + 2 > 4) {
			rarr[n - i - 1] = (arr[i] + 2) % 4;
		}
		else {
			rarr[n - i - 1] = arr[i] + 2;
		}
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j];
		}
	}
	
	solve();

	cout << num <<'\n';
	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			for (int j = 0; j < n; j++) {
				cout << arr2[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	
}