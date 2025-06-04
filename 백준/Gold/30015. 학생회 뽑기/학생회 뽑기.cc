#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[200001];
int ans;

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> v;
	for (int i = 20; i >= 0; i--) {
		int cnt = 0;
		v.clear();
		for (int j = 0; j < n; j++) {
			if ((arr[j] >> i) & 1) {
				cnt++;
				v.push_back(arr[j]);
			}
		}
		if (cnt >= k) {
			break;
		}
	}

	for (int i = 20; i >=0; i--) {
		int cnt = 0;
		vector<int> tmp;
		for (int j = 0; j < v.size(); j++) {
			if ((v[j] >> i) & 1) {
				cnt++;
				tmp.push_back(v[j]);
			}
		}
		if (cnt >= k) {
			ans += 1 << i;
			v = tmp;
		}
	}
 }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << ans;
}
