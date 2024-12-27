#include <iostream>
using namespace std;

int n, k, p, w;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> p >> w;

	if (p % w == 0) {
		ans = p / w;
	}
	else {
		ans = p / w + 1;
	}

	cout << ans;
}