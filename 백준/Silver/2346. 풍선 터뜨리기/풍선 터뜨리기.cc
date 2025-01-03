#include <iostream>
#include <vector>
using namespace std;

int n;
int balloon[1000];
vector<int> v;

void solve() {
	int index = 0;
	int count = 0;
	while (count < n) {
		int move = balloon[index];
		balloon[index] = 0;
		v.push_back(index + 1);
		count++;
		if (count == n) {
			break;
		}

		if (move < 0) {
			while (move < 0) {
				if (index == 0) {
					index = n - 1;
				}
				else {
					index--;
				}

				if (balloon[index]) {
					move++;
				}
			}
		}
		else {
			while (move > 0) {
				index = (index + 1) % n;

				if (balloon[index]) {
					move--;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> balloon[i];
	}
	solve();

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}