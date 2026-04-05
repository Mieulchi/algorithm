#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	while (true) {
		string s = "";
		cin >> s;

		if (s == "0") {
			break;
		}

		int len = s.length();
		int flag = 1;

		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[len - 1 - i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}