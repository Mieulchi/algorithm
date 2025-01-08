#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int basket[1001];

void solve() {
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			basket[j] = c;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	for (int i = 1; i <= n; i++) {
		cout << basket[i] << ' ';
	}
}