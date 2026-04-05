#include <iostream>
#include <string>
using namespace std;

int main() {
	int n[10];
	int mod[10];

	for (int i = 0; i < 10; i++) {
		cin >> n[i];
		mod[i] = n[i] % 42;
	}

	int count = 10;
	for (int i = 1; i < 10; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (mod[i] == mod[j]) {
				count--;
				break;
			}
		}
	}
	cout << count << endl;
}