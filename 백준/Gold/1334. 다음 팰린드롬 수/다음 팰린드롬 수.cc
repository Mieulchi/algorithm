#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int length = s.length();

	string cmp1, cmp2, cmp3;
	string result;

	if (length == 1) {
		if (s == "9") {
			cout << 11;
		}
		else {
			cout << to_string(stoi(s) + 1);
		}
	}
	else {
		if (length % 2 == 1) {
			for (int i = 0; i < length / 2 + 1; i++) {
				cmp1 += s[i];
			}
			for (int i = length / 2 + 1; i < length; i++) {
				cmp2 += s[i];
			}
		}
		else {
			for (int i = 0; i < length / 2; i++) {
				cmp1 += s[i];
			}
			for (int i = length / 2; i < length; i++) {
				cmp2 += s[i];
			}
		}
		//짝수, 홀수 관계 없이 대칭되는 부분만 보기위해 문자열 자르기(12345 -> 12, 12 뒤집어서 21을 45와 비교 / 123456 -> 123, 뒤집어서 321과 456 비교) 
		for (int i = length / 2 - 1; i >= 0; i--) {
			cmp3 += s[i];
		}
		int flag = 0;
		for (int i = 0; i < cmp3.length(); i++) {
			if (cmp3[i] > cmp2[i]) {
				flag = 1;
				break;
			}
			else if (cmp3[i] < cmp2[i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			result += cmp1;
			result += cmp3;
		}
		else {
			result = cmp1;
			int idx = cmp1.length() - 1;

			while (true) {
				int check = result[idx] - '0' + 1;
				if (check == 10) {
					result[idx] = '0';
					if (idx == 0) {
						string tmp = result;
						result = '1' + tmp;
						break;
					}
					idx--;
				}
				else {
					result[idx] = check + '0';
					break;
				}
			}

			for (int i = length / 2 - 1; i >= 0; i--) {
				result += result[i];
			}
		}

		cout << result;
	}
}