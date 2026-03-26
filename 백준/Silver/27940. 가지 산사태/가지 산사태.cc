#include <iostream>
using namespace std;

#define INF 1e18

typedef long long ll;

int n, m, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	
	int a, b;
	ll sum = 0;
	int i;
	for (i = 1; i <= m; ++i) {
		cin >> a >> b;
		sum += b;
		if (sum > k) {
			break;
		}
	}
	if (sum > k) {
		cout << i << ' ' << 1;
	}
	else {
		cout << -1;
	}
}