#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v;
int cnt;
bool printed = false;

void dfs(int idx) {
	if (printed) {
		return;
	}

	if (idx < v.size()) {
		int pr = v[idx].first, pc = v[idx].second;
		
		for (int i = 1; i <= 9; ++i) {
			bool flag = true;
			for (int c = 0; c < 9; ++c) {
				if (arr[pr][c] == i) {
					flag = false;
					break;
				}
			}
			for (int r = 0; r < 9; ++r) {
				if (arr[r][pc] == i) {
					flag = false;
					break;
				}
			}
			int tr = (pr / 3) * 3;
			int tc = (pc / 3) * 3;
			for (int r = tr; r < tr + 3; ++r) {
				for (int c = tc; c < tc + 3; ++c) {
					if (arr[r][c] == i) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				arr[pr][pc] = i;
				dfs(idx + 1);
				if (!printed) {
					arr[pr][pc] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	else {
		for (int r = 0; r < 9; ++r) {
			for (int c = 0; c < 9; ++c) {
				cout << arr[r][c];
			}
			cout << '\n';
		}
		printed = true;
		return;
	}

}

void solve() {
	
	dfs(0);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	for (int r = 0; r < 9; ++r) {
		cin >> s;
		for (int c = 0; c < 9; ++c) {
			arr[r][c] = s[c] - '0';
			if (!arr[r][c]) {
				v.push_back({ r, c });
			}
		}
	}

	solve();
}