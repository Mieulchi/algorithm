#include <iostream>
using namespace std;

int N;

void solve() {
    int now = 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << now << ' ' << j << '\n';
		}
		now = now == 2 ? 1 : 2;
	}
	for (int i = 1; i <= N; i++) {
		cout << now << ' ' << i << '\n';
	}
	now = now == 2 ? 1 : 2;
	for (int i = N; i >= 1; i--) {
		for (int j = N - i + 1; j <= N; j++) {
			cout << now << ' ' << j << '\n';
		}
		now = now == 2 ? 1 : 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << N * N + 2 * N << '\n';
	solve();
}