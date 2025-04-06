#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> chokchok[100001];
pair<int, int> chokchok2[100001];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else {
		return p1.first > p2.first;
	}
}

bool cmp2(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

void solve() {
	sort(chokchok, chokchok + n, cmp);
	sort(chokchok2, chokchok2 + n, cmp2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chokchok[i].first >> chokchok[i].second;
		chokchok2[i] = chokchok[i];
	}
	solve();
	cout << chokchok[0].first << ' ' << chokchok[0].second << ' ' << chokchok[1].first << ' ' << chokchok[1].second << '\n';
	cout << chokchok2[0].first << ' ' << chokchok2[0].second << ' ' << chokchok2[1].first << ' ' << chokchok2[1].second;
}