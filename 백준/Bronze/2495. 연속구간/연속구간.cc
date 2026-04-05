#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s[3];
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;

		char tmp = s[0];
		int count = 1;
		int maxcount = 0;
		for (int j = 1; j < 8; j++) {
			if (tmp == s[j]) {
				count++;
			}
			else {
				tmp = s[j];
				if (count > maxcount) {
					maxcount = count;
				}
				count = 1;
			}
		}
		if (count > maxcount) {
			maxcount = count;
		}
		if (!maxcount) {
			cout << 1 << endl;
		}
		else {
			cout << maxcount << endl;
		}
	}		
}