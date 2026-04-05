#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a[26] = { 0 };

	for (int i = 0; i < s.length(); i++) {
		int n = tolower(s[i]) - 'a';
		a[n]++;
	}

	int max = 0;
	int flag = 0;
	int index = 0;

	for (int i = 0; i < 26; i++) {
		if (a[i] >= max) {
			if (a[i] == max) {
				flag = 1;
			}
			else {
				flag = 0;
			}
			max = a[i];
			index = i;
		}
	}
	if (flag == 1) {
		cout << "?" << endl;
	}
	else {
		cout << char('A' + index) << endl;
	}
}