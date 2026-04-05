#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int a = 0, b = 0;
	int len = s.length();
	if (len == 2) {
		a = s[0] - '0';
		b = s[1] - '0';
	}
	else if (len == 3) {
		if (s[2] == '0') {
			a = s[0] - '0';
			b = (s[1] - '0') * 10 + s[2] - '0';
		}
		else {
			a = (s[0] - '0') * 10 + s[1] - '0';
			b = s[2] - '0';
		}
	}
	else {
		if (s[len - 1] == '0') {
			int i = 0;
			for (; i < len - 2 ; i++) {
				a += (s[i] - '0') * (int)(pow(10, s.length() - 3 - i));
			}
			b = (s[i] - '0') * 10 + s[i+1] - '0';
		}
		else {
			int i = 0;
			for (; i < len - 1; i++) {
				a += (s[i] - '0') * (int)(pow(10, s.length() - 2 - i));
			}
			b = s[i] - '0';
		}
	}
	cout << a + b;
}