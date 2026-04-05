#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	string s;
	cin >> s;

	int len = s.length();
	char* c = new char[len];
	for (int i = 0; i < len; i++) {
		c[i] = s[i];
	}

	sort(c, c + len, cmp);

	for (int i = 0; i < len; i++) {
		cout << c[i];
	}
}