#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000000000000

int t;
long long n;
int dp[101];
long long ans = 0;

void solve() {
	dp[1] = 1;
	dp[10] = 1;
	dp[25] = 1;

	for (int i = 1; i < 100; ++i) {
		
		dp[i] = dp[i - 1] + 1;
		
		if (i >= 10) {
			dp[i] = min(dp[i], dp[i - 10] + 1);
		}
		
		if (i >= 25) {
			dp[i] = min(dp[i], dp[i - 25] + 1);
		}
	}
}

void find_ans(long long n) {
	ans = 0;
	long long i = 1;
	while (true) {
		if (n <= i * 100 - 1) {
			break;
		}
		i *= 100;
	}

	while (n) {
		if (i > n) {
			i /= 100;
			continue;
		}
		ans += dp[n / i];
		n -= (n / i) * i;
		i /= 100;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	cin >> t;
	while (t--) {
		cin >> n;
		find_ans(n);
		cout << ans << '\n';
	}
}