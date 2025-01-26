#include <iostream>
#include <vector>
using namespace std;

int r, c, k;

char routes[5][5];
int visited[5][5];
int ans;

void solve(int pr, int pc, int cnt) {
	visited[pr][pc] = 1;
	if (pr == 0 && pc == c - 1) {
		if (k == cnt) {
			ans++;
		}
		visited[pr][pc] = 0;
		return;
	}
	if (pr + 1 < r && !visited[pr + 1][pc] && routes[pr + 1][pc] != 'T') {
		solve(pr + 1, pc, cnt + 1);
	}
	if (pr - 1 >= 0 && !visited[pr - 1][pc] && routes[pr - 1][pc] != 'T') {
		solve(pr - 1, pc, cnt + 1);
	}
	if (pc + 1 < c && !visited[pr][pc + 1] && routes[pr][pc + 1] != 'T') {
		solve(pr, pc + 1, cnt + 1);
	}
	if (pc - 1 >= 0 && !visited[pr][pc - 1] && routes[pr][pc - 1] != 'T') {
		solve(pr, pc - 1, cnt + 1);
	}
	visited[pr][pc] = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			routes[i][j] = s[j];
		}
	}

	solve(r - 1, 0, 1);

	cout << ans;
}