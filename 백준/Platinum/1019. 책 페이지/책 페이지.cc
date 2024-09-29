#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long counts[10][10];
long long sum[11];

int main() {
	int n;
	cin >> n;

	if (n < 10) {
		for (int i = 1; i <= n; i++) {
			counts[i][0]++;
		}

		for (int i = 0; i < 10; i++) {
			cout << counts[i][0] << ' ';
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			counts[i][0] = 1;
		}

		int count = 1;
		for (int i = 10; i * 10 <= n; i *= 10, count++) {
			if (count == 1) {
				counts[0][1] = 9;
			}
			else if (count == 2) {
				int op = 0;
				op +=  10 * counts[0][0] + pow(10, count - 1);
				counts[0][count] += 9 * op;
			}
			else {
				int op = 0;
				op += 10 * (counts[0][count - 1] / 9);
				op += pow(10, count - 1);

				counts[0][count] += 9 * op;
			}

			for (int j = 1; j < 10; j++) {
				counts[j][count] += pow(10, count);
				for (int k = 0; k < count; k++) {
					counts[j][count] += 9 * counts[j][k];
				}
			}
		}

		long long tmp[10] = { 0 };
		string s = to_string(n);
		for (int i = 0; i < s.length(); i++) {
			tmp[i] = s[i] - '0';
		}

		int fix = count;
		for (int i = 0; i < s.length(); i++, count--) {
			if ((i == 0 && tmp[i] == 1) || tmp[i] == 0) {

			}
			else {
				if (i == 0) {
					long long op = 0;
					op += pow(10, count - 1);
					
					op += 10 * (counts[0][count - 1] / 9);
					
					counts[0][fix] += (tmp[i] - 1) * op;
				}
				else {
					long long op = 0;
					counts[0][fix] += pow(10, count);
					op += counts[0][count] / 9;

					counts[0][fix] += tmp[i] * op;
				}

				for (int j = 1; j < 10; j++) {
					//요기는 1~9 더하는곳
					long long op = 0;
					for (int k = 0; k < count; k++) {
						op += counts[j][k];
					}

					if (i == 0) {
						counts[j][fix] += (tmp[i] - 1) * op;
					}
					else {
						counts[j][fix] += tmp[i] * op;
					}
					if (j < tmp[i]) {
						counts[j][fix] += pow(10, count);
					}



				}
				int k;
				for (k = 0; k < i; k++) {
					counts[tmp[k]][fix] += pow(10, count) * tmp[i];
				}
			}
		}

	

		for (int i = 0; i < s.length(); i++) {
			counts[tmp[i]][fix]++;
		}
		counts[0][0]--;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= fix; j++) {
				sum[i] += counts[i][j];
			}
		}

		for (int i = 0; i < 10; i++) {
			cout << sum[i] << ' ';
		}
	}
}