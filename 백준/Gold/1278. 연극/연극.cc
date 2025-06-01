#include <iostream>
using namespace std;

int n;

void solve(int k) {
	if (!k) {
		return;
	}
	solve(k - 1);
	cout << k << '\n';
	solve(k - 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << (1 << n) - 1 << '\n';
	solve(n);
	cout << n;
}