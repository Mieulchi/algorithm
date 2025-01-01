#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<int> v1, v2, ans;

void solve() {
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		if (!binary_search(v2.begin(), v2.end(), v1[i])) {
			ans.push_back(v1[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}
	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		v2.push_back(tmp);
	}

	solve();

	if (!ans.size()) {
		cout << 0;
	}
	else {
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
	}
}