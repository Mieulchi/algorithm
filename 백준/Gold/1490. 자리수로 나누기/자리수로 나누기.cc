#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long n;

int arr[10];

int check(long long tmp) {
	int flag = 1;
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			continue;
		}
		if (tmp % (s[i] - '0')) {
			flag = 0;
			break;
		}
	}

	return flag;
}

void solve() {
	if (check(n)) {
		cout << n;
	}
	else {
		int i = 0;
		int count = 1;
		while (true) {
			long long tmp;
			n *= 10;
			for (int j = 0; j < pow(10, count); j++) {
				tmp = n;
				tmp += j;
				if (check(tmp)) {
					cout << tmp;
					return;
				}
			}
			count++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();
}