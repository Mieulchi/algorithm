#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;

	string* s = new string[k];

	for (int i = 0; i < k; i++) {
		cin >> s[i];
	}

	int max = 0;
	for (int i = 0; i < k; i++) {
		int count = 0;
		for (int j = 0; j < k; j++) {
			if (i == j) {
				continue;
			}
			if (s[i][j] == 'Y') {
				count++;
			}
			else {
				for (int l = 0; l < k; l++) {
					if (s[j][l]) {
						if (s[i][l] == 'Y' && s[j][l] == 'Y') {
							count++;
							break;
						}
					}
				}
			}
		}
		if (count > max) {
			max = count;
		}
	}

	cout << max;
}