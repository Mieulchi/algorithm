#include <iostream>
using namespace std;

int n, m;
long long dp[100001];

void solve() {
	int from, to;
	while (m--) {
		cin >> from >> to;
		cout << dp[to] - dp[from - 1] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		dp[i] = dp[i - 1] + tmp;
	}
	solve();
}