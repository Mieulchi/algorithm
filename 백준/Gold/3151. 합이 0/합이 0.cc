#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[10000];
long long ans;

void solve() {
	sort(arr, arr + N);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int sum = arr[i] + arr[j];
			int left = lower_bound(arr + j + 1, arr + N, sum * - 1) - arr;
			int right = upper_bound(arr + j + 1, arr + N, sum * - 1) - arr;
			ans += (right - left);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve();
	cout << ans;
}