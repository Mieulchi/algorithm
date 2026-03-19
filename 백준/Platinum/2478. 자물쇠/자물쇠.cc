#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define INF 1e18

typedef long long ll;

int n, p, q, k1, k2;
int arr[500];
int cpy[500];

void solve() {
	for (k2 = 1; k2 < n; ++k2) {
		for (int i = 0; i < n; ++i) {
			cpy[i] = arr[i];
		}

		for (int j = 0; j < k2; ++j) {
			int mem = cpy[n - 1];
			for (int i = n - 1; i > 0; --i) {
				cpy[i] = cpy[i - 1];
			}
			cpy[0] = mem;
		}

		int start = 0, end = 0;
		for (int i = 1; i < n; ++i) {
			if ((cpy[i] % n) + 1 == cpy[i - 1]) {
				end = start = i;
				while (end < n && (cpy[end] + 1 == cpy[end - 1] || (cpy[end] == n && cpy[end - 1] == 1))) {
					end++;
				}
				p = start--, q = end--;
				while (start <= end) {
					swap(cpy[start++], cpy[end--]);
				}
				break;
			}
		}

		bool flag = true;
		for (int i = 1; i < n; ++i) {
			if (cpy[i] == 1) {
				k1 = n - i;
			}
			if (cpy[i] == cpy[i - 1] + 1 || (cpy[i] == 1 && cpy[i - 1] == n)) {
				continue;
			}
			flag = false;
			break;
		}
		if (flag && k1 > 0 && k1 < n) {
			break;
		}
	}

	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	solve();
	cout << k1 << '\n' << p << ' ' << q << '\n' << k2;

}