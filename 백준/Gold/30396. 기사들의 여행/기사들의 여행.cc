#include <iostream>
#include <queue>
using namespace std;

int chess[2][4][4];
int visited[65536];
int amask;
queue<int> q;

void f(int bitmask, int b) {
	if ((bitmask >> b) & 1) {
		return;
	}
	else {
		if (!visited[bitmask + (1 << b)]) {
			q.push(bitmask + (1 << b));
		}
	}
}

void move(int bitmask) {
	for (int i = 0; i < 16; i++) {
		if ((bitmask >> i) & 1) {
			int r = i / 4;
			int c = i % 4;
			int tmp = bitmask - (1 << i);
			if (r < 2) {
				if (c < 3) {
					f(tmp, (r + 2) * 4 + c + 1);
				}
				if (c > 0) {
					f(tmp, (r + 2) * 4 + c - 1);
				}
			}
			if (r > 1) {
				if (c < 3) {
					f(tmp, (r - 2) * 4 + c + 1);
				}
				if (c > 0) {
					f(tmp, (r - 2) * 4 + c - 1);
				}
			}
			if (c < 2) {
				if (r < 3) {
					f(tmp, (r + 1) * 4 + c + 2);
				}
				if (r > 0) {
					f(tmp, (r - 1) * 4 + c + 2);
				}
			}
			if (c > 1) {
				if (r < 3) {
					f(tmp, (r + 1) * 4 + c - 2);
				}
				if (r > 0) {
					f(tmp, (r - 1) * 4 + c - 2);
				}
			}
		}
	}
}

int ans;
void solve() {
	int cnt = 0;
	while (!q.empty()) {
		queue<int> tmp;
		while (!q.empty()) {
			tmp.push(q.front());
			q.pop();
		}

		while (!tmp.empty()) {
			int front = tmp.front();
			tmp.pop();
			if (visited[front]) {
				continue;
			}
			visited[front] = 1;
			move(front);
		}
		if (visited[amask]) {
			ans = cnt;
			break;
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int b = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 4; j++) {
				chess[k][i][j] = s[j] - '0';
				if (k == 0) {
					b += chess[0][i][j] ? (1 << (i * 4 + j)) : 0;
				}
				else {
					amask += chess[1][i][j] ? (1 << (i * 4 + j)) : 0;
				}
			}
		}
	}
	q.push(b);
	solve();
	cout << ans;
}