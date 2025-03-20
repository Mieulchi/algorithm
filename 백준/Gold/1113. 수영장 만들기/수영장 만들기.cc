#include <iostream>
#include <queue>
using namespace std;

int n, m;
int pool[102][102];
int height;
int ans;

void dfs(int r, int c, int i) {
	if (r > n + 1 || r < 0 || c > m + 1|| c < 0) {
		return;
	}
	if (pool[r][c] >= i) {
		return;
	}
	pool[r][c] = i;
	dfs(r + 1, c, i);
	dfs(r - 1, c, i);
	dfs(r, c + 1, i);
	dfs(r, c - 1, i);
}

void cnt(int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (pool[i][j] < k) {
				ans++;
				pool[i][j] = k;
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= height; i++) {
		dfs(0, 0, i);
		cnt(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	if (n > 2 && m > 2) {
		string s;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			for (int j = 1; j <= m; j++) {
				if (s[j - 1] - '0' > height) {
					height = s[j - 1] - '0';
				}
				pool[i][j] = s[j - 1] - '0';		
			}
		}
		solve();
	}
	cout << ans;
}