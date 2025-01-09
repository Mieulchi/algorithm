#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int arr[236197];
int ans;

void solve() {
	int a = n;
	arr[a] = 1;
	v.push_back(a);

	while (true) {
		int sum = 0;
		while (a > 0) {
			int tmp = a % 10; 
			int mul = 1;
			for (int i = 0; i < m; i++) {
				mul *= tmp;
			}
			a /= 10;
			sum += mul;
		}
		if (arr[sum] == 1) {
			int count = 0;
			for (int i = 0; i < v.size(); i++) {
				if (sum == v[i]) {
					break;
				}
				ans++;
			}
			break;
		}
		else {
			a = sum;
			arr[a] = 1;
			v.push_back(a);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	solve();

	cout << ans;
}