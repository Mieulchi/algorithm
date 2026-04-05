#include <iostream>
#include <string>
using namespace std;

string s[200001];

int main() {
	int size = 0;
	while (true) {
		string tmp;
		cin >> tmp;
		if (tmp == "-") {
			break;
		}
		s[size++] = tmp;
	}

	int c[27] = { 0 };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			c[s[i][j] - 'A'] = 1;
		}
	}


	while (true) {
		//store puzzle prototype
		int puzzle[27] = { 0 };
		int counts[27] = { 0 };
		//puzzle to be compared
		int compare[27] = { 0 };

		string tmp;
		cin >> tmp;
		if (tmp == "#") {
			break;
		}
		for (int i = 0; i < tmp.length(); i++) {
			puzzle[tmp[i] - 'A']++;
		}
		for (int i = 0; i < 26; i++) {
			compare[i] = puzzle[i];
		}

		for (int i = 0; i < size; i++) {
			int flag = 1;
			for (int j = 0; j < s[i].length(); j++) {
				if (compare[s[i][j] - 'A'] == 0) {
					flag = 0;
					break;
				}
				else {
					compare[s[i][j] - 'A']--;
				}
			}
			if (flag == 1) {
				int tmp[27] = { 0 };
				//s = brilliant; 
				for (int j = 0; j < s[i].length(); j++) {
					tmp[s[i][j] - 'A'] = 1;
				}
				//tmp[a], tmp[p], tmp[l], tmp[e] = 1
				for (int j = 0; j < 26; j++) {
					if (tmp[j] == 1) {
						counts[j]++;
					}
				}
			}
			for (int i = 0; i < 26; i++) {
				compare[i] = puzzle[i];
			}
		}
		int min = 10000000, max = counts[0];
		int minindex = 0, maxindex = 0;

		for (int j = 0; j < 26; j++) {
			if (min > counts[j] && puzzle[j] != 0) {
				min = counts[j];
				minindex = j;
			}
			if (max < counts[j]) {
				max = counts[j];
				maxindex = j;
			}
		}
		for (int j = 0; j < 26; j++) {
			if (min == counts[j] && puzzle[j] != 0) {
				cout << char(j + 'A');
			}
		}
		cout << ' ' << min << ' ';

		for (int j = 0; j < 26; j++) {
			if (max == counts[j] && puzzle[j] != 0) {
				cout << char(j + 'A');
			}
		}
		cout << ' ' << max << '\n';
	}
}