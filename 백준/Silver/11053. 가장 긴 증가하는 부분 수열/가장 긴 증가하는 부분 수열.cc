#include <iostream>
using namespace std;

int sq[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;

	int length = 0;

	for (int i = 0; i < n; i++) {
		cin >> sq[i];
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (sq[j] < sq[i] && dp[j] > max) {
				max = dp[j];
			}
		}
		dp[i] += max;
		if (dp[i] > result) {
			result = dp[i];
		}
	}

	cout << result;
}