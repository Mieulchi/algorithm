#include <iostream>
#include <string>
using namespace std;

long long k;
int ans;

long long pow(int t) {
	long long res = 1;
	if (t) {
		for (int i = 0; i < t; i++) {
			res *= 10;
		}
	}
	return res;
}

void solve() {
	long long left = 1;
	long long right = 1000000000000000;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		long long len = to_string(mid).length();
		for (int i = 1; i < len; i++) {
			sum +=  i * (pow(i) - pow(i - 1));
		}
		sum += len * (mid - pow(len - 1) + 1);
		sum += mid;
		sum -= mid / 4;
		string tmp = to_string(mid);
		if (mid % 4) {
			tmp += mid % 2 ? '2' : '0';
		}
		len = tmp.length();
		if (sum - len + 1 <= k && k <= sum) {
			long long p = sum - tmp.length();
			for (int i = 0; i < tmp.length(); i++) {
				if (p + i + 1 == k) {
					ans = tmp[i] - '0';
					break;
				}
			}
			break;
		}
		else {
			if (sum > k) {
				right = mid - 1;
			}
			else if (k > sum - len + 1) {
				left = mid + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> k;
		if (!k) {
			break;
		}
		solve();
		cout << ans << '\n';
	}
}