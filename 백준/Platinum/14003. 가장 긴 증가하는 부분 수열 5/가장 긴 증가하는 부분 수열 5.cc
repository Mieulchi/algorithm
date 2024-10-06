#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int seq[1000001];
int dp[1000001];
int result[1000001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	dp[0] = seq[0];
	int pointer = 0;
	result[0] = 0;

	for (int i = 1; i < n; i++) {
		if (dp[pointer] < seq[i]) {
			dp[++pointer] = seq[i];
			result[i] = pointer;
		}
		else {
			int index = lower_bound(dp, dp + pointer, seq[i]) - dp;
			if (dp[index] >= seq[i]) {
				dp[index] = seq[i];
				result[i] = index;
			}
		}
	}

	cout << pointer + 1 << '\n';

	vector<int> v;
	for (int i = n - 1; i >= 0; i--) {
		if (result[i] == pointer) {
			v.push_back(seq[i]);
			pointer--;
			if (pointer == -1) {
				break;
			}
		}
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}
}
