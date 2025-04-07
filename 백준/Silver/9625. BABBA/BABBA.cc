#include <iostream>
using namespace std;

int k;
int dpa, dpb;

void solve() {
	int preva = 1;
	int prevb = 0;
	for (int i = 0; i < k; i++) {
		dpb = preva + prevb;
		dpa = prevb;
		preva = dpa;
		prevb = dpb;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	solve();
	cout << dpa << ' ' << dpb;
}