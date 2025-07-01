#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MOD 1000000007

int n;
string u = "UNIST";

int dp[100000][6];
string arr[6];
string mem[6];

int ans;

void solve() {
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int len = min(5, int(s.length()));

		mem[0] = "";
		for (int j = 0; j < len; j++) {
			string tmp;
			for (int k = 0; k <= j; k++) {
				tmp += s[k];
				mem[k + 1] = tmp;
			}
		}
		if (i) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k <= len; k++) {
					if (dp[i - 1][j] && arr[j] + mem[k] == arr[j + k]) {
						dp[i][j + k] += dp[i - 1][j];
						dp[i][j + k] %= MOD;
					}
				}
			}
		}
		else {
			for (int k = 0; k <= len; k++) {
				if (arr[k] == mem[k]) {
					dp[0][k]++;
				}
			}
		}
	}
	ans = dp[n - 1][5];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		string tmp;
		for (int j = 0; j <= i; j++) {
			tmp += u[j];
		}
		arr[i + 1] = tmp;
	}

	cin >> n;
	solve();
	cout << ans;
}