#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string arr[1000];
string ans;

bool cmp(string s1, string s2) {
	return s1 + s2 > s2 + s1;
}

void solve() {
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int flag = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] != "0") {
			flag = 1;
		}
	}

	if (!flag) {
		ans = "0";
	}
	else {
		solve();
	}
	
	cout << ans;
}