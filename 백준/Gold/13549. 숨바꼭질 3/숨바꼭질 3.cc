#include <iostream>
using namespace std;

int mem[100001];

int getTime(int n, int k) {
	
	int time = 0;
	int tmp = k;
	while (true) {
		if (n > tmp / 2) {
			if (n - tmp / 2 > tmp - n) {
				return tmp - n;
			}
			else {
				return n - tmp / 2;
			}
		}
		if (tmp % 2 == 0) {
			tmp /= 2;
		}
		else {
			time += tmp % 2;
			int a = getTime(n, (tmp + 1));
			int b = getTime(n, (tmp - 1));
			a > b ? time += b : time += a;
			break;
		}
	}

	return time;
}

int main() {
	int n, k;
	cin >> n >> k;

	int time = 0;
	int zeroflag = 0;

	if (n == 0) {
		zeroflag = 1;
	}

	if (n >= k) {
		time = n - k;
		cout << time;
	}
	else {
		if (n == 0) {
			n = 1;
		}

		int gettime = getTime(n, k);
		
		if (zeroflag == 1) {
			gettime++;
		}
		cout << gettime;
	}
}