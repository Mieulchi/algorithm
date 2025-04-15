#include <iostream>
#include <string>
using namespace std;

int n;
int arr[2000001];
int ans;

void preprocess() {
	arr[1] = 1;
	for (int i = 2; i <= 2000000; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= 2000000; j += i) {
				arr[j] = 1;
			}
		}
	}
}

int is_pelin(int i) {
	string s = to_string(i);
	int flag = 1;
	for (int i = 0; i <= s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void solve() {
	
	for (int i = n; i <= 2000000; i++) {
		if (!arr[i] && is_pelin(i)) {
			ans = i;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	preprocess();
	solve();
	cout << ans;
}