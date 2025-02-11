#include <iostream>
#include <map>
using namespace std;

int n;
int a, b;
map<pair<int, int>, int> points;
int ans;

void solve() {
	map<pair<int, int>, int> mem = points;
	for (auto it = mem.begin(); it != mem.end(); it++) {
		pair<int, int> origin = { it->first.first, it->first.second };
		pair<int, int> point1 = { origin.first + a , origin.second };
		pair<int, int> point2 = { origin.first , origin.second + b };
		int flag=1;
		if (points[point1] && points[point2]) {
			if (points[{origin.first + a, origin.second + b}]) {
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		pair<int, int> point;
		cin >> point.first >> point.second;
		points[point] = 1;
	}

	solve();

	cout << ans;
}