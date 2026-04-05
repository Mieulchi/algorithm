#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e18

typedef long long ll;

int n, k, m;
int graph[201][201];
int base[201][201];
int res[201][201];

void mul(int (&dest)[201][201], int(&mat1)[201][201], int(&mat2) [201][201]) {
	int temp[201][201] = { 0, };
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= n; ++l) {
				temp[i][j] |= (mat1[i][l] & mat2[l][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dest[i][j] = temp[i][j];
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		res[i][i] = 1;
	}

	while (k) {
		if (k % 2) {
			mul(res, res, base);
		}
		mul(base, base, base);
		k /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> m;

	int a, b;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		base[i][a] = graph[i][a] = 1;
		base[i][b] = graph[i][b] = 1;
	}

	solve();

	while (m--) {
		cin >> a >> b;
		if (res[a][b]) {
			cout << "death\n";
		}
		else {
			cout << "life\n";
		}
	}
}