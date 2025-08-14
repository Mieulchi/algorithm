#include <iostream>
#include <vector>
using namespace std;

int n;
long long ans;

vector<pair<int, int>> v;

bool check(int a, int b, int c, int d) {
	return !(a == c || b == d || abs(c - a) == abs(d - b));
}
void recursive(int col) {
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < v.size(); j++) {
			if (!check(v[j].first, v[j].second, i, col)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (col == n - 1) {
				ans++;
				return;
			}
			else {
				v.push_back({ i, col });
				recursive(col + 1);
				v.pop_back();
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		v.push_back({ i,0 });
		recursive(1);
		v.pop_back();

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n == 1) {
		ans = 1;
	}
	else {
		solve();
	}
	cout << ans;
}