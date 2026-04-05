#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

long long n;
long long l, k;
int arr[1000000];
int sum[1000000];
int ans = 1;

void solve() {
	long long speed = arr[0] ? 2 : 1;
	long long total = 0;
	while (total < n * l - 1) {
		++ans;

		long long move = speed;

		long long d = move / l;
		long long jumps = d * sum[l - 1];

		long long remain = move % l;

		if (remain) {
			int current = total % l;

			if (current + remain >= l) {
				jumps += (sum[l - 1] - sum[current]);
				jumps += sum[(current + move) % l];
			}
			else {
				jumps += (sum[current + remain] - sum[current]);
			}

		}
		
		speed += jumps;
		total += move;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> k;
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		arr[a - 1] = 1;
	}
	sum[0] = arr[0];
	for (int i = 1; i < l; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}
	solve();
	cout << ans;
}