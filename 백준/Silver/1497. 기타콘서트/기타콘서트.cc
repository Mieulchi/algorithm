#include <iostream>
#include <cmath>
using namespace std;

int n, m;
pair<string, int[50]> s[10];
int check[50];
int scount;
int ans;

void checkBinary(int n) {
	string st;
	while (n) {
		if (n % 2) {
			st += '1';
		}
		else {
			st += '0';
		}
		n /= 2;
	}
	int count = 0;
	for (int i = st.length() - 1; i >= 0; i--) {
		if (st[i] - '0') {
			count++;
			for (int j = 0; j < m; j++) {
				check[j] |= s[i].second[j];
			}
		}
	}

	int flag = 0;
	int tmp = 0;
	for (int i = 0; i < m; i++) {
		if (check[i]) {
			flag = 1;
			tmp++;
		}
	}
	if (flag && (!scount || tmp >= scount)) {
		if (tmp == scount) {
			if (!ans || ans > count) {
				ans = count;
				scount = tmp;
			}
		}
		else {
			ans = count;
			scount = tmp;
		}
	}
}
void init() {
	for (int j = 0; j < 50; j++) {
		check[j] = 0;
	}
}

void solve() {
	int k = pow(2, n);	
	for (int i = 1; i < k; i++) {
		checkBinary(i);
		init();
	}
	if (!ans) {
		ans = -1;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> s[i].first >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp[j] == 'Y') {
				s[i].second[j] = 1;
			}
			else {
				s[i].second[j] = 0;
			}
		}
	}
	solve();

	cout << ans;
}