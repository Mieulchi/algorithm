#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int cols;
	cin >> cols;
	string s;
	cin >> s;

	int len = s.length();
	int rows = len / cols;

	char** arr = new char*[rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new char[cols];
	}

	string result = "";
	int idx = 0;
	for (int i = 0; i < rows && idx < len; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < cols; j++) {
				arr[i][j] = s[idx++];
			}
		}
		else {
			for (int j = cols - 1; j >= 0; j--) {
				arr[i][j] = s[idx++];
			}
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << arr[j][i];
		}
	}
}