#include <iostream>
#include <algorithm>
using namespace std;

int m;

short arr[21];

void solve() {
	string s;
	int n;
	cin >> s;
	if (s == "add") {
		cin >> n;
		arr[n] |= 1;
	}
	else if (s == "remove") {
		cin >> n;
		arr[n] &= 0;
	}
	else if (s == "check") {
		cin >> n;
		cout << arr[n] << '\n';
	}
	else if (s == "toggle") {
		cin >> n;
	
		arr[n] ^= 1;
	}
	else if (s == "all") {
		for (int i = 1; i <= 20; i++) {
			arr[i] |= 1;
		}
	}
	else if (s == "empty") {
		for (int i = 1; i <= 20; i++) {
			arr[i] &= 0;
		}
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> m;

	for (int i = 0; i < m; i++) {
		solve();
	}
}