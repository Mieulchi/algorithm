#include <iostream>
#include <map>
using namespace std;

int n, m;
map<int, int> mp;
int arr[50];

void solve() {
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int count = 0;
		for (int j = 1; j < m - 1; j++) {
			if (s[j] == '.') {
				count++;
			}
			else {
				if (count != m - 2) {
					arr[count] = 1;
					mp[s[j] - '0'] = count;
				}
				break;
			}
		}
		
	}
	int rank = 1;
	for (int i = m - 1; i >= 0; i--) {
		if (arr[i]) {
			arr[i] = rank++;
		}
	}

	for (int i = 1; i <= 9; i++) {
		cout << arr[mp[i]] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();
}