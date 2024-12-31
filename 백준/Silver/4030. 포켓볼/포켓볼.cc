#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a, b;
int ans;
vector<long long> v;

void solve() {
	long long i = 2;
	while (true) {
		long long m = i * i;
		if (m <= a) {
			i++;
			continue;
		}
		if (m >= b) {
			break;
		}
		if (binary_search(v.begin(), v.end(), m)) {
 			ans++;
		}
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 2;
	long long sum = 1;
	while (sum <= 1000000000) {
		sum += i++;
		v.push_back(sum + 1);
	}

	i = 1;
	while (true) {
		cin >> a >> b;
		ans = 0;
		if (a == 0 && b == 0) {
			break;
		}
		solve();
		cout << "Case " << i << ": " << ans << "\n";
		i++;
	}
}