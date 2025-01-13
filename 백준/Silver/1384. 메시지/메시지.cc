#include <iostream>
#include <map>
using namespace std;

int n;
string names[20];
char article[20][20];

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> names[i];
		for (int j = 1; j < n; j++) {
			cin >> article[i][j];
		}
	}

	int flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (article[i][j] == 'N') {
				flag = 0;
				int t = i;
				t -= j;
				if (t < 0) {
					t += n;
				}
				cout << names[t] << " was nasty about " << names[i] << '\n';
			}
		}
	}
	if (flag) {
		cout << "Nobody was nasty\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 1;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			cout << "Group " << i++ << '\n';


			solve();
			
			cout << '\n';
		}
	}
}