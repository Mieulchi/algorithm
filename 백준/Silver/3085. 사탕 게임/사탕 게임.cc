#include <iostream>
#include <algorithm>
using namespace std;

int n;
char arr[50][50];
int ans;

void checkR(int i) {
	int cnt = 1;
	char tmp = arr[i][0];
	for (int k = 1; k < n; k++) {
		if (tmp == arr[i][k]) {
			cnt++;
		}
		else {
			if (cnt > ans) {
				ans = cnt;
			}
			cnt = 1;
			tmp = arr[i][k];
		}
	}
	if (cnt > ans) {
		ans = cnt;
	}
}

void checkC(int i) {
	int cnt = 1;
	char tmp = arr[0][i];
	for (int k = 1; k < n; k++) {
		if (tmp == arr[k][i]) {
			cnt++;
		}
		else {
			if (cnt > ans) {
				ans = cnt;
			}
			cnt = 1;
			tmp = arr[k][i];
		}
	}
	if (cnt > ans) {
		ans = cnt;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checkR(i);
			checkC(j);
			if (i != n - 1) {
				swap(arr[i][j], arr[i + 1][j]);
				checkR(i);
				checkR(i + 1);
				checkC(j);
				swap(arr[i][j], arr[i + 1][j]);
			}
			if (j != n - 1) {
				swap(arr[i][j], arr[i][j + 1]);
				checkR(i);
				checkC(j);
				checkC(j + 1);
				swap(arr[i][j], arr[i][j + 1]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}
	solve();
	cout << ans;
}