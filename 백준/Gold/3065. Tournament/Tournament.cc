#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n, m;
int p;
pair<int, int> rnk[257];
int tree[257];

void solve() {
	cin >> n;
	for (int i = (1 << n); i < (1 << (n + 1)); i++) {
		tree[i] = i - (1 << n) + 1;
	}
	for (int i = n - 1; i >=0; i--) {
		for (int j = (1 << i); j < (1 << (i + 1)); j++) {
			cin >> tree[j];
		} 
	}

	rnk[tree[1]].first = 1;
	rnk[tree[1]].second = 1 << n - 1;
	
	int level = n;
	for (int i = 2; i < (1 << (n + 1)); i++) {
		if ((i & (i - 1)) == 0) {
			level--;
		}
		if (tree[i] != tree[i / 2]) {
			rnk[tree[i]].first = rnk[tree[i / 2]].first + 1;
			rnk[tree[i]].second = 1 << n; 
		}
		if (level) {
			rnk[tree[i]].second -= 1 << (level - 1);
		}
	}


	cin >> m;
	while (m--) {
		cin >> p;
		cout << "Player " << p << " can be ranked as high as " << rnk[p].first << " or as low as " << rnk[p].second << ".\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}