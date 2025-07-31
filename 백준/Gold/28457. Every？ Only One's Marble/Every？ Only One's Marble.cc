#include <iostream>
using namespace std;

int idx = 0;
pair<int, int> keys[32];
int board[396];

pair<int, int> dices[60];

int n, S, W, G;
int I;
string ans = "WIN";
int minsaeng;

int loc = 0;
int isIsland = 0;

void buy() {
	S -= board[loc];
	board[loc] = 0;
}

void event() {
	if (loc % (n - 1) == 0) {
		int t = loc / (n - 1);
		//시작점
		if (t == 0) {
			S += W;
		}
		//인무도
		else if (t == 1) {
			isIsland = 3;
		}
		//민생지원금
		else if (t == 2) {
			S += minsaeng;
			minsaeng = 0;
		}
		//머스크
		else if (t == 3) {
			S += W;
			loc = 0;
		}
	}
	//황열
	else if (board[loc] == -1) {
		int c = keys[idx].first;
		int d = keys[idx].second;
		idx = (idx + 1) % G;
		if (c == 1) {
			S += d;
		}
		else if (c == 2) {
			if (S < d) {
				ans = "LOSE";
				return;
			}
			S -= d;
		}
		else if (c == 3) {
			if (S < d) {
				ans = "LOSE";
				return;
			}
			S -= d;
			minsaeng += d;
		}
		else if (c == 4) {
			loc += d;
			if (loc >= 4 * n - 4) {
				S += W * (loc / (4 * n - 4));
				loc %= (4 * n - 4);
			}
			event();
		}
	}
	else {
		if (board[loc]) {
			if (S < board[loc]) {
				ans = "LOSE";
				return;
			}
			buy();
		}
	}
}

void solve() {
	for (int i = 0; i < I; i++) {
		int a = dices[i].first, b = dices[i].second;

		if (isIsland) {
			if (a == b) {
				isIsland = 0;
				continue;
			}
			else {
				isIsland--;
				continue;
			}
		}
		loc += (a + b);
		if (loc >= 4 * n - 4) {
			S += W * (loc / (4 * n - 4));
			loc %= (4 * n - 4);
		}
		event();
		if (ans == "LOSE") {
			break;
		}
	}
	for (int i = 0; i < 4 * n - 4; i++) {
		if (board[i] != -1 && i % (n - 1) != 0 && board[i]) {
			ans = "LOSE";
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> S >> W >> G;
	for (int i = 0; i < G; i++) {
		cin >> keys[i].first >> keys[i].second;
	}
	for (int i = 1; i <= 4 * n - 4; i++) {
		if (i % (n - 1) == 0) {
			continue;
		}
		char c;
		cin >> c;
		if (c == 'G') {
			board[i] = -1;
		}
		else {
			int t;
			cin >> t;
			board[i] = t;
		}
	}
	cin >> I;
	for (int i = 0; i < I; i++) {
		cin >> dices[i].first >> dices[i].second;
	}
	solve();
	cout << ans;
}