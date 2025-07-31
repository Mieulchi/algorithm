#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> m;
vector<string> v;
int total;

void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin, s)) {
		if (!m[s]) {
			v.push_back(s);
		}
		m[s]++;
		total++;
	}

	sort(v.begin(), v.end());
	cout << fixed;
	cout.precision(4);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ' << double(m[v[i]]) / total * 100 << '\n';
	}
}