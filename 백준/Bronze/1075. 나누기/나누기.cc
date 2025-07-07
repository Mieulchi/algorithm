#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, f;
	cin >> n >> f;
	int o = n - n % 100;
	for (int i = 0; i < 100; i++) {
		if ((o + i) % f == 0) {
			if (i < 10) {
				cout << '0';
			}
			cout << i;
			break;
		}
	}
}