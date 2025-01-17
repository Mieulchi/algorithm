#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a, b;
int prime[100001];
vector<int> v;
int ans;

void solve() {
	for (int i = a; i <= b; i++) {
		int j = i;
		int count = 0;
		int index = 0;
		while (j > 1) {
			if (j % v[index] == 0) {
				count++;
				j /= v[index];
			}
			else {
				index++;
			}
		}
		if (find(v.begin(), v.end(), count) != v.end()) {
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	for (int i = 2; i <= 100000; i++) {
		int j;
		if (!prime[i]) {
			j = i + i;
			v.push_back(i);
		}
		else {
			continue;
		}

		while (j <= 100000) {
			prime[j] = 1;
			j += i;
		}
	}

	solve();

	cout << ans;
}