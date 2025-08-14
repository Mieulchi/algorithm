#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n;

void f(int s, int e) {
	if (s > e) {
		return;
	}
	if (s == e) {
		cout << v[s] << '\n';;
		return;
	}
	int i;
	for (i = s; i <= e; i++) {
		if (v[i] > v[s]) {
			break;
		}
	}
	f(s + 1, i - 1);
	f(i, e);
	cout << v[s] << '\n';
}

void solve() {
	while (cin >> n) {
		v.push_back(n);
	}
	f(0, v.size() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}