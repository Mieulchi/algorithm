#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int n, m;

vector<int> v[10001];
vector<int> maxs;
int maxc;

int check[10000];
int tmpc;

void dfs(int g) {
	for (int i = 0; i < v[g].size(); i++) {
		if (!check[v[g][i]]) {
			check[v[g][i]] = 1;
			dfs(v[g][i]);
			tmpc++;
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) { 
		check[i] = 1;
		dfs(i);

		if (maxc <= tmpc) {
			
			if (maxc < tmpc) {
				maxs.clear();
			}
			maxc = tmpc;
			maxs.push_back(i);
		}
		tmpc = 0;
		memset(check, 0, n * sizeof(int));
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);	

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b - 1].push_back(a - 1);
	}

	solve();

	for (int i = 0; i < maxs.size(); i++) {
		cout << maxs[i] + 1 << ' ';
	}

}