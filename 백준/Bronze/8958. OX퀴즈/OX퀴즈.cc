#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int tmp = 1;
		int score = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				score += tmp;
				tmp++;
			}
			else {
				tmp = 1;
			}
		}

		cout << score << endl;
	}

}