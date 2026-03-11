#include <iostream>
#include <string>
using namespace std;

#define INF 1000000007

struct Trie {
	bool isEnd;
	int next[10];
};

Trie trie[100005];
int num;

int getNode() {
	int idx = num++;

	trie[idx].isEnd = false;
	for (int i = 0; i < 10; ++i) {
		trie[idx].next[i] = 0;
	}

	return idx;
}

bool insert(string s) {
	int curr = 1;
	bool result = true;
	bool isNew = false;
	for (char c : s) {
		int idx = c - '0';
		if (trie[curr].isEnd) {
			result = false;
		}
		if (trie[curr].next[idx] == 0) {
			trie[curr].next[idx] = getNode();
			isNew = true;
		}
		curr = trie[curr].next[idx];
	}
	trie[curr].isEnd = true;

	if (!isNew) {
		result = false;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	string s;

	bool result;

	cin >> t;
	while (t--) {
		cin >> n;

		result = true;
		num = 1;
		getNode();

		while (n--) {
			cin >> s;

			if (result) {
				result = insert(s);
			}
		}

		cout << (result ? "YES\n" : "NO\n");
	}
}