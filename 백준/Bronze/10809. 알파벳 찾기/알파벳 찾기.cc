#include <iostream>
#include <string>
using namespace std;

int main() {
	int a[26];
	string s;

	cin >> s;

	for (int i = 0; i < 26; i++) {
		a[i] = -1;
	}

	for (int i = 0; i < s.length(); i++) {
		int n = s[i] - 'a';
		if (a[n] == -1) {
			a[n] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", a[i]);
	}


	// printf("%d", 'c' - 'a'); => 2
}