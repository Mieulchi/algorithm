#include <iostream>
#include <string>
using namespace std;

long long a, b, ans;

void getGcd() {
	while (true) {
		if (b % a == 0) {
			ans = a;
			break;
		}
		long long tmp = a;
		a = b % a;
		b = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	if (a > b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}

	getGcd();

	for (int i = 0; i < ans; i++) {
		cout << 1;
	}
}