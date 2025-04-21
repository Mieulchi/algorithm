#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
int r;
int flag;
int key;
map<int, int> yak;

void solve() {
	cin >> r;
	int t;
	for (int i = 0; i < r; i++) {
		cin >> t;
		int e;
		vector<int> v;

		while (t--) {
			cin >> e;
			if (yak[e]) {
				v.push_back(yak[e]);
			}
			else {
				if (flag && e == key) {
					v.push_back(yak[e]);
				}
				else {
					v.clear();
					while (t--) {
						cin >> e;
					}
					break;
				}
			}
		}

		if (!v.empty()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
		}
		else {
			cout << "YOU DIED";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int efficiency, name;
	while (n--) {
		cin >> efficiency >> name;
		yak[efficiency] = name;
		if (name == 0) {
			flag = 1;
			key = efficiency;
		}
	}
	solve();
}