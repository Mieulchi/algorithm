#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	int count = 0;
	if (x > y) {
		count = x + y / 10;
		count += y;
	}
	else {

		count = y + x / 10;
		count += x;
	}

	cout << count;
}