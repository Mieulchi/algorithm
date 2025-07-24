#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[16];
int sum[65536];
vector<int> valids[161];
int ans;

void solve() {
	for (int i = 1; i < (1 << n); i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				s += arr[j];
			}
		}
		sum[i] = s;
	}

	for (int i = 1; i < (1 << n); i++) {
		for (int j = i; j; j = (j - 1) & i) {
			int t = j ^ i;
			if (sum[j] == sum[t]) {
				valids[sum[j]].push_back(i);
				break;
			}
		}
	}

	for (int i = 1; i < 161; i++) {
		for (int j = i; j < 161; j++) {
			vector<int> v1 = valids[i];
			vector<int> v2 = valids[j];
			for (int k = 0; k < v1.size(); k++) {
				for (int l = 0; l < v2.size(); l++) {
					if (i != j || k != l) {
						if ((v1[k] & v2[l]) == 0) {
							ans = max(ans, i * j);
						}
					}
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
		cin >> arr[i];
	}
	solve();
	if (!ans) {
		ans = -1;
	}
	cout << ans;
}