#include <iostream>
#include <string>
using namespace std;

int n;
int ans;

int pow(int k) {
	int res = 1;
	for (int i = 0; i < k; i++) {
		res *= 9;
	}
	return res;
}

void solve() {
	string s = to_string(n);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		ans += pow(len - i - 1) * (s[i] - '0');
		ans -= s[i] >= '4' ? pow(len - i - 1) : 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
	cout << ans;
}