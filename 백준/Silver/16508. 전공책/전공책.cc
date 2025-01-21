#include <iostream>
#include <vector>
using namespace std;

int c[26];
int n;
int prices[16];
vector<char> books[16];
int cmp[26];

int ans;

void init() {
	for (int i = 0; i < 26; i++) {
		cmp[i] = 0;
	}
}

int check(vector<int> v) {
	init();

	int price = 0;
	for (int i = 0; i < v.size(); i++) {
		price += prices[v[i]];
		for (int j = 0; j < books[v[i]].size(); j++) {
			cmp[books[v[i]][j] - 'A']++;
		}
	}
	int flag = 1;
	for (int i = 0; i < 26; i++) {
		if (c[i] > cmp[i]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		return price;
	}
	else {
		return 0;
	}
}

void rec(vector<int> v, int index, int count) {
	if (!count) {
		int result = check(v);
		if (result) {
			if (!ans || ans > result) {
				ans = result;
			}
		}
	}
	else {
		for (int i = index; i < n; i++) {
			vector<int> tmp = v;
			tmp.push_back(i);
			rec(tmp, i + 1, count - 1);
		}
	}
}

void solve() {
	for (int i = 1; i <= 10; i++) {
		vector<int> v;
		rec(v, 0, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		c[s[i] - 'A']++;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string tmp;
		cin >> a >> tmp;

		prices[i] = a;
		for (int j = 0; j < tmp.length(); j++) {
			if (c[tmp[j] - 'A']) {
				books[i].push_back(tmp[j]);
			}
		}
	}
	
	solve();

	if (!ans) {
		ans = -1;
	}
	cout << ans;
}