#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int mat[10][10];

int checkSqr(int n) {
	int tmp = sqrt(n);

 	if (n == tmp * tmp) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			mat[i][j] = tmp[j] - '0';
		}
	}

	string s = "";

	int result = -1;

	int len = 0;
	if (n > m) {
		len = n;
	}
	else {
		len = m;
	}

	while (len > 0) {
		int xinterval, yinterval;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (xinterval = 1; xinterval <= m; xinterval++) {
					for (yinterval = 1; yinterval <= n; yinterval++) {
						//오른쪽
						if (j + (len - 1) * xinterval < m) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i][j + k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						//아래
						if (i + (len - 1) * yinterval < n) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i + k * yinterval][j] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						//왼쪽
						if (j - (len - 1) * xinterval >= 0) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i][j - k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						//위 
						if (i - (len - 1) * yinterval >= 0) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i - k * yinterval][j] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						//가로세로 다움직이는 네 경우
						if (i + (len - 1) * yinterval < n && j + (len - 1) * xinterval < m) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i + k * yinterval][j + k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						if (i - (len - 1) * yinterval >= 0 && j + (len - 1) * xinterval < m) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i - k * yinterval][j + k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						if (i + (len - 1) * yinterval < n && j - (len - 1) * xinterval >= 0) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i + k * yinterval][j - k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
						if (i - (len - 1) * yinterval >= 0 && j - (len - 1) * xinterval >= 0) {
							s = "";
							for (int k = 0; k < len; k++) {
								s += mat[i - k * yinterval][j - k * xinterval] + '0';
							}
							int tmp = stoi(s);
							if ((checkSqr(tmp) == 1) && result < tmp) {
								result = tmp;
							}
						}
					}
				}
			}
		}
		len--;
	}
	cout << result;
}