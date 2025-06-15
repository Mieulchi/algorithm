#include <iostream>
using namespace std;

int t;
int n, m;
int arr[500][500];
int mem[500][500]; 
int min_[500];
string ans;

void init() {
	for (int i = 1; i < m; i++) {
		min_[i] = -10000001;
	}
}

void solve() {
	ans = "YES";
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (j){
				mem[i][j] = arr[i][0] - arr[i][j];
				if (mem[i][j] - mem[i][j - 1] >= min_[j]) {
					min_[j] = mem[i][j] - mem[i][j - 1];
				}
				else {
					ans = "NO";
				}
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;	
		solve();
		cout << ans << '\n';
	}
}