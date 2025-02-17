#include <iostream>
using namespace std;

string s1, s2;
int ans = 51;

void solve() {
	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		int cnt = 0;
		for (int j = i; j < i + s1.length(); j++) {
			if (s1[j - i] != s2[j]) {
				cnt++;
			}
		}
		if (cnt < ans) {
			ans = cnt;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;
	solve();

	cout << ans;
}