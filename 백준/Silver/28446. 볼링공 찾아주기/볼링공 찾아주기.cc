#include <iostream>
#include <map>
using namespace std;

int m;
map<int, int> mp;
int n, x, w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;
	while (m--) {
		cin >> n;
		if (n == 1) {
			cin >> x >> w;
			mp[w] = x;
		}
		else {
			cin >> w;
			cout << mp[w] << '\n';
		}
	}
}