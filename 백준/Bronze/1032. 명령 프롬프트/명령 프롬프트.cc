#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	string* s = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	string result = "";
	int len = s[0].length();
	for (int i = 0; i < len; i++) {
		int flag = 1;
		for (int j = 0; j < n - 1; j++) {
			if (s[j][i] != s[j + 1][i]) {
				flag = 0;
			}
		}
		if (flag) {
			result += s[0][i];
		}
		else {
			result += '?';
		}
	}
	result += "\0";

	delete[] s;

	cout << result;

}