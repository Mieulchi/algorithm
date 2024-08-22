#include <iostream>
using namespace std;

//(100+1+ | 01)+
// 1001 10001 01 0101

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;

		int len = s.length();

		string answer = "YES";


		//100+1+
		int pattern1 = 0;

		//01
		int pattern2 = 0;

		//remember pattern
		int was = 0;

		string buffer = "";
		buffer += s[0];

		int zeroCount = 0, oneCount = 0;


		if (buffer[0] == '0') {
			pattern2 = 1;
		}
		else {
			pattern1 = 1;
		}

		if (len == 1) {
			answer = "NO";
		}
		else {
			for (int j = 1; j < len; j++) {
				if (s[j] == '0') {
					if (j == len - 1) {
						answer = "NO";
						break;
					}
					else {
						if (buffer == "") {
							if (s[j + 1] == '0') {
								if (was == 1) {
									if (oneCount >= 2) {
										pattern1 = 1;
										pattern2 = 0;
										buffer += '1';
										buffer += s[j];
										zeroCount = 1;
										oneCount = 0;
									}
									else {
										answer = "NO";
										break;
									}
								}
								else {
									answer = "NO";
									break;
								}
							}
							else {
								pattern2 = 1;
								pattern1 = 0;
								buffer += s[j];
								zeroCount = 0;
								oneCount = 0;
							}
						}
						else {
							if (pattern1) {
								buffer += s[j];
								zeroCount++;
							}
							else {
								answer = "NO";
								break;
							}
						}
					}
				}
				else {
					if (j == len - 1) {
						if (buffer == "") {
							answer = "NO";
							break;
						}
						else {
							if (pattern2 == 1) {
								break;
							}
							else {
								if (zeroCount >= 2) {
									break;
								}
								else {
									answer = "NO";
									break;
								}
							}
						}
					}
					else {
						if (buffer == "") {
							pattern1 = 1;
							pattern2 = 0;
							buffer += s[j];
							zeroCount = 0;
							oneCount = 0;
						}
						else {
							if (pattern1) {
								if (zeroCount <= 1) {
									answer = "NO";
									break;
								}
								else {

									if (s[j + 1] == '1') {
										buffer += s[j];
										oneCount++;
									}
									else {
										buffer = "";
										was = 1;
										oneCount++;
									}
								}

							}
							else {
								buffer = "";
								zeroCount = 0;
								oneCount = 0;
							}
						}
					}
				}
			}
		}
		cout << answer << '\n';
	}
}