#include <iostream>
using namespace std;

int n, m;
int mat[100][100];
int ans;

void solve() {
	int l, b;
	for (int i = 0; i < n; i++) {
		cin >> l >> b;
		for (int j = l; j < l + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				mat[j][k]++;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j]) {
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve(); 
	cout << ans;
}