#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> v2;
int q;

void solve() {
	int size = v.size();
	vector<int> tmp;
	vector<int> tmp2;
	if (v2[size / 2 - 1] > v2[size - 1] - v2[size / 2 - 1]) {
		cout << v2[size - 1] - v2[size / 2 - 1] << '\n';
		for (int i = 0; i <= size / 2 - 1; i++) {
			tmp.push_back(v[i]);
			if (tmp.size() > 1) {
				tmp2.push_back(tmp2[tmp.size() - 2] + v[i]);
			}
			else {
				tmp2.push_back(v[i]);
			}
		}
	}
	else {
		cout << v2[size / 2 - 1] << '\n';
		for (int i = size / 2; i < size; i++) {
			tmp.push_back(v[i]);
			if (tmp.size() > 1) {
				tmp2.push_back(tmp2[tmp.size() - 2] + v[i]);
			}
			else {
				tmp2.push_back(v[i]);
			}
		}
	}
	v = tmp;
	v2 = tmp2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> q;
	int a, b;
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			v.push_back(b);
			if (v.size() > 1) {
				v2.push_back(v2[v.size() - 2] + b);
			}
			else {
				v2.push_back(b);
			}
		}
		else {
			solve();
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}