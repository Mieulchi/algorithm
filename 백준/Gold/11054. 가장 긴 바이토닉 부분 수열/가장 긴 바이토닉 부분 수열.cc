#include <iostream>
#include <climits>
using namespace std;

int sq[1001];
int dp1[1001];
int dp2[1001];

int main() {
	int n;
	cin >> n;

	int length = 0;

	for (int i = 0; i < n; i++) {
		cin >> sq[i];
	}

	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (sq[j] < sq[i] && dp1[j] > max) {
				max = dp1[j];
			}
		}
		dp1[i] += max;
	}

	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		int min = 0;
		for (int j = n - 1; j >= i; j--) {
			if (sq[j] < sq[i] && dp2[j] > min) {
				min = dp2[j];
			}
		}
		dp2[i] += min;
	}

	int result = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int op1 = dp1[i];
		int maxtmp = 0;
		for (int j = i + 1; j < n; j++) {
			if (dp2[j] > maxtmp && sq[j] != sq[i]) {
				maxtmp = dp2[j];
			}
		}
		if (op1 + maxtmp > result) {
			result = op1 + maxtmp;
		}
	}


	cout << result;
}