#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define INF 1000000007

int num = 1;

struct Trie {
	map<string, int> m;
};

Trie trie[15005];

void insert(vector<string> v) {
	int curr = 1;
	for (string s : v) {

		if (trie[curr].m.find(s) == trie[curr].m.end()) {
			trie[curr].m.insert({ s, ++num });
		}

		curr = trie[curr].m[s];
	}
}

void dfs(string s, int curr, int depth) {
	for (int i = 0; i < depth; ++i) {
		cout << "--";
	}
	cout << s << '\n';

	for (auto& it : trie[curr].m) {
		dfs(it.first, it.second, depth + 1);
	}

}

void print() {
	for (auto& it : trie[1].m) {
		dfs(it.first, it.second, 0);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k;

		vector<string> v;
		for (int j = 0; j < k; ++j) {	
			cin >> s;
			v.push_back(s);
		}
		insert(v);
	}

	print();
}