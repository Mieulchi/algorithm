#include <iostream>
#include <climits>
using namespace std;

int arr[100001];
int n;
long long ans;

void solve() {

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long tmp = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > tmp) {
			tmp++;
		}
		else {
			if (ans < tmp) {
				ans = tmp;
			}
			tmp = arr[i];
		}
	}
	if (ans < tmp) {
		ans = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}