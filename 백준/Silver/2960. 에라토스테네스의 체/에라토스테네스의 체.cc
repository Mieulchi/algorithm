#include <iostream>
using namespace std;

int n, k;
short arr[1001];
int cache;

void solve() {
	int m = 2, t = m;
	while (k) {
		if (t > n) {
			while (arr[m]) {
				m++;
			}
			t = m;
		}
		
		if (!arr[t]) {
			arr[t] = 1;
			cache = t;
			k--;
		}
		t += m;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	solve();

	cout << cache;
}