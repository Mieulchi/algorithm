#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

/*
	흠 한 개씩 순서대로 켜보자고?
	n개 키는건 -> n - 1개 킨 상태에서 어느 곳에서 하나를 켠 후가 되잔아

	dp[i][j] = i개 사용해서 j상태 만든 경우
	-> 4중 반복문이 되어버리는데 계속
*/

int n, ans = INF, p;
int arr[16][16];
string s;
int dp[1 << 16];

void solve() {

	for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
		for (int i = 0; i < n; ++i) {
			if ((bitmask >> i) & 1) {
				for (int j = 0; j < n; ++j) {
					if (i != j) {
						int next = bitmask | (1 << j);
						dp[next] = min(dp[next], dp[bitmask] + arr[i][j]);
					}
				}
			}
		}
	}

	for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((bitmask >> i) & 1) {
				++cnt;
			}
		}
		if (cnt >= p) {
			ans = min(ans, dp[bitmask]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		dp[i] = INF;
	}


	cin >> s;
	int flag = 0;
	int bitmask = 0;
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'Y') {
			++cnt;
			flag = 1;
			bitmask += (1 << i);
		}
	}
	dp[bitmask] = 0;
	cin >> p;

	if (cnt < p) {
		if (flag) {
			solve();
		}
		else {
			ans = -1;
		}
	}
	else {
		ans = 0;
	}

	cout << ans;
}