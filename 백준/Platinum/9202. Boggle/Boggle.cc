#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

int n, ans, cnt;
string ansString;

struct Trie {
	bool isEnd;
	int arr[26];
};

Trie trie[2400005];
int num = 1;

string board[4][4];

int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int score[8] = { 0, 0, 1, 1, 2, 3, 5, 11 };

unordered_set<string> visited;

bool search(string s) {
	int curr = 1;

	for (char c : s) {
		int idx = c - 'A';
		if (trie[curr].arr[idx] == 0) {
			return false;
		}
		curr = trie[curr].arr[idx];
	}
	if (trie[curr].isEnd) {
		return true;
	}
	return false;
}

void dfs(int r, int c, int bitmask, int depth, int limit, string s) {
	if (depth != limit) {

		for (int i = 0; i < 8; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
				int idx = nr * 4 + nc;
				if ((bitmask >> idx) & 1) {
					continue;
				}
				dfs(nr, nc, bitmask | (1 << idx), depth + 1, limit, s + board[nr][nc]);
			}
		}
	}
	else {
		bool result = search(s);

		if (result && visited.find(s) == visited.end()) {
			visited.insert(s);
			cnt++;
			ans += score[limit - 1];
			if (ansString == "") {
				ansString = s;
			}
			else if (ansString.length() <= s.length()) {
				ansString = min(s, ansString);
			}
		}
	}
}

void solve() {
	ans = 0;
	ansString = "";
	cnt = 0;
	visited.clear();

	for (int limit = 8; limit > 0; --limit) {
		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				int mask = 1 << (r * 4 + c);

				dfs(r, c, mask, 1, limit, board[r][c]);
			}
		}
	}
}

void insert(string s) {
	int curr = 1;
	for (char c : s) {
		int idx = c - 'A';

		if (trie[curr].arr[idx] == 0) {
			trie[curr].arr[idx] = ++num;
		}

		curr = trie[curr].arr[idx];
	}
	trie[curr].isEnd = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		insert(s);
	}

	cin >> n;
	while (n--) {
		for (int r = 0; r < 4; ++r) {
			cin >> s;
			for (int c = 0; c < 4; ++c) {
				board[r][c] = s[c];
			}
		}
		solve();
		cout << ans << " " << ansString << " " << cnt << '\n';
	}

}