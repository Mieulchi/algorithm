#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[10000];
int n[20001];
int p[20001];
long long zero;
long long ans;

void solve() {
	if (zero > 2) {
		ans += zero * (zero - 1) * (zero - 2) / 6;
	}
	if (zero) {
		for (int i = 1; i <= 10000; i++) {
			if (n[i] && p[i]) {
				ans += zero * (n[i] * p[i]);
			}
		}
	}
	
	sort(arr, arr + N);

	int left = lower_bound(arr, arr + N, 0) - arr;
	int right = upper_bound(arr, arr + N, 0) - arr;

	for (int i = right; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			ans += n[arr[i] + arr[j]];
		}
	}

	for (int i = 0; i < left - 1; i++) {
		for (int j = i + 1; j < left; j++) {
			ans += p[(arr[i] + arr[j]) * -1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (!arr[i]) {
			zero++;
		}
		arr[i] > 0 ? p[arr[i]]++ : n[arr[i] * -1]++;
	}
	solve();
	cout << ans;
}