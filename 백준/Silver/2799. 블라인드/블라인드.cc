#include <iostream>
using namespace std;

int n, m;
string s[502];
int arr[5];

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int k = 0; k < 5; k++) {
				if (s[i * 5 + 1 + k][j * 5 + 1] == '*') {
					cnt++;
				}
			}
			arr[cnt]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> s[0];
	for (int i = 1; i <= 5 * n; i++) {
		cin >> s[i];
	}
	solve(); 
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
}