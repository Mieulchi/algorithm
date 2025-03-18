#include <iostream>
using namespace std;

string s;
int ans;

void solve() {
	int score = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			score++;
		}
		else if (s[i] == ')') {
			score--;
		}
		else if (s[i] == '{') {
			score += 2;
		}
		else if (s[i] == '}') {
			score -= 2;
		}
		else if (s[i] == '[') {
			score += 3;
		}
		else if (s[i] == ']') {
			score -= 3;
		}
		else {
			if (score > ans) {
				ans = score;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	solve();
	cout << ans;
}