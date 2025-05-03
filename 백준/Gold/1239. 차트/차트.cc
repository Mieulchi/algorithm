#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[8];
int check[8];
int ans;

void recursive(vector<int> v) {
	if (v.size() == n) {
		int moved = 0;
		int sum = 0;
		int from = 0;
		int tmp = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += arr[v[i]];
			if (sum >= 50) {
				if (sum == 50) {
					tmp++;
					moved += arr[v[from]];
					sum -= arr[v[from]];
					from++;
				}
				else {
					while (sum > 50) {
						sum -= arr[v[from]];
						moved += arr[v[from]];
						from++;
					}
				}
			}
			if (moved >= 50) {
				break;
			}
		}
		if (tmp > ans) {
			ans = tmp;
		}
	}
	else {
		for (int i = 0;i < n;i++) {
			vector<int> tmp = v;
			if (!check[i]) {
				tmp.push_back(i);
				check[i] = 1;
				recursive(tmp);
				check[i] = 0;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		vector<int> v;
		check[i] = 1;
		v.push_back(i);
		recursive(v);
		check[i] = 0;
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
	cout << ans;
}