#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ans, guess;

string solve() {

	int b = 0, g = 0, w = 0;
	string cpy = guess;

	for (int loop = 0; loop < 3; ++loop) {
		for (int i = 0; i < cpy.length(); ++i) {
			for (int j = 0; j < ans.length(); ++j) {
				if (cpy[i] == ans[j] && cpy[i] != ' ') {
					if (loop == 0 && i == j) {
						b++;
						cpy[i] = ' ';
						ans[j] = ' ';
						break;
					}
					else if (loop == 1 && abs(i - j) == 1) {
						g++;
						cpy[i] = ' ';
						ans[j] = ' ';
						break;
					}
					else if (loop == 2) {
						w++;
						cpy[i] = ' ';
						ans[j] = ' ';
						break;
					}


				}
			}
		}
	}


	return (guess + ": " + to_string(b) + " black, " + to_string(g) + " grey, " + to_string(w) + " white");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> ans;
		if (ans == "#") {
			break;
		}
		cin >> guess;

		cout << solve() << '\n';
	}
}
