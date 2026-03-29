#include <iostream>
using namespace std;

#define INF 1e18

typedef long long ll;

int n, m, k;
char map[100][100];
string ans;

void solve() {
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	char ch;
	while (t--) {
		cin >> n >> m;
		int cnt = 0;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				cin >> ch;
				if (ch == '.') {
					cnt++;
				}
			}
		}
		ans += cnt % 2 ? "sewon\n" : "pizza\n";
	}
	cout << ans;
}