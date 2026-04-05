#include <iostream>
#include <cmath>
using namespace std;

string shape[6];
int possib[11][11] = { 0 };
int falseflag = 0;

void check_posib(int n) {
	if (shape[1][4 * n + 1] == '#' || shape[3][4 * n + 1] == '#') {
		falseflag = 1;
		return;
	}

	//0
	for (int i = 1; i < 4; i++) {
		if (shape[i][4 * n + 1] == '#') {
			possib[n][0] = -1;
			break;
		}
	}
	//1
	for (int i = 0; i < 5; i++) {
		if (shape[i][4 * n] == '#' || shape[i][4 * n + 1] == '#') {
			possib[n][1] = -1;
			break;
		}
	}
	//2
	if (shape[1][4 * n] == '#' || shape[1][4 * n + 1] == '#' || shape[3][4 * n + 1] == '#' || shape[3][4 * n + 2] == '#') {
		possib[n][2] = -1;
	}
	//3
	if (shape[1][4 * n] == '#' || shape[1][4 * n + 1] == '#' || shape[3][4 * n] == '#' || shape[3][4 * n + 1] == '#') {
		possib[n][3] = -1;
	}
	//4
	if (shape[0][4 * n + 1] == '#' || shape[1][4 * n + 1] == '#' || shape[3][4 * n] == '#' || shape[3][4 * n + 1] == '#' || shape[4][4 * n] == '#' || shape[4][4 * n + 1] == '#') {
		possib[n][4] = -1;
	}
	//5
	if (shape[1][4 * n + 1] == '#' || shape[1][4 * n + 2] == '#' || shape[3][4 * n] == '#' || shape[3][4 * n + 1] == '#') {
		possib[n][5] = -1;
	}
	//6
	if (shape[1][4 * n + 1] == '#' || shape[1][4 * n + 2] == '#' || shape[3][4 * n + 1] == '#') {
		possib[n][6] = -1;
	}
	//7
	for (int i = 1; i < 5; i++) {
		if (shape[i][4 * n] == '#' || shape[i][4 * n + 1] == '#') {
			possib[n][7] = -1;
			break;
		}
	}
	//8
	if (shape[1][4 * n + 1] == '#' || shape[3][4 * n + 1] == '#') {
		possib[n][8] = -1;
	}
	//9
	if (shape[1][4 * n + 1] == '#' || shape[3][4 * n] == '#' || shape[3][4 * n + 1] == '#') {
		possib[n][9] = -1;
	}
}

int main() {
	int n;
	cin >> n;

	//안내판 입력
	for (int i = 0; i < 5; i++) {
		cin >> shape[i];
	}

	//안내판 자릿수마다 가능한 숫자 2차원배열 possib에 저장
	for (int i = 0; i < n; i++) {
		check_posib(i);
		if (falseflag == 1) {
			cout << -1;
			return 0;
		}
	}

	long double sum = 0.0;
	long double total = 1.0;
	//한자리면 그냥 더하기
	if (n == 1) {
		total = 0.0;
		for (int j = 0; j < 10; j++) {
			if (possib[0][j] != -1) {
				sum += j;
				total += 1.0;
			}
		}
	}
	//두자리이상이면 다른 자리 경우의수(총 경우의수 / 그 자리 가능한 경우의 수)만큼 더하기
	else {
		double count[11] = { 0 };
		for (int i = 0; i < n; i++) {
			double tmp = 0.0;
			for (int j = 0; j < 10; j++) {
				if (possib[i][j] != -1) {
					 tmp += 1.0;
				}
			}
			if (tmp == 0.0) {
				tmp = 1.0;
			}
			count[i] = tmp;
			total *= tmp;
		}
		
		for (int i = 0; i < n; i++) {
			double deg = 1.0;
			for (int j = 0; j < n - i - 1; j++) {
				deg *= 10.0;
			}
			
			for (int j = 0; j < 10; j++) {
				if (possib[i][j] != -1) {
					sum += deg * j * (total / count[i]);
				}
			}
		}
	}


	if (total == 0.0) {
		total = 1.0;
	}
	if (sum == 0.0) {
		cout << -1;
	}
	else {
		double result = sum / total;
		cout << result;
	}
}