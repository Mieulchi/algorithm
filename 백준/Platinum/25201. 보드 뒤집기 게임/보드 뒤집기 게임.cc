#include <iostream>
using namespace std;

int n, m;
int r[100000];
int c[100000];

int r2[100000];
int c2[100000];

void solve() {
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		r[a]++;
		c[b]++;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		r2[a]++; c2[b]++;
	}

	int flag = 1;
	for (int i = 0; i < 100000; i++) {
		if (r[i] % 2 != r2[i] % 2) {
			flag = 0;
			break;
		}
		if (c[i] % 2 != c2[i] % 2) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;


	solve();
}