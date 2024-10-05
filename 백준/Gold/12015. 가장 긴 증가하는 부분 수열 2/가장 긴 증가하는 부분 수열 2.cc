#include <iostream>
#include <algorithm>
using namespace std;

int seq[1000001];
int dp[1000001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	dp[0] = seq[0];
	int pointer = 0;

	for (int i = 1; i < n; i++) {
		int change = 0;
		if (dp[pointer] < seq[i]) {
			dp[++pointer] = seq[i];
		}
		else {
			int index = lower_bound(dp, dp + pointer, seq[i]) - dp;
			if (dp[index] > seq[i]) {
				dp[index] = seq[i];
			}
		}
	}

	cout << ++pointer << '\n';

}
