#include <iostream>
using namespace std;

int n;
int arr[2001];
int ans;

bool iddfs(int cur, int depth, int limit) {
	if (cur == n) {
		return true;
	}

	if (depth == limit) {
		return false;
	}

	if (cur << (limit - depth) < n) {
		return false;
	}

	arr[depth] = cur;

	for (int i = depth; i >= 0; --i) {

		int nextSum = cur + arr[i];
		if (nextSum < 2001) {
			if (iddfs(nextSum, depth + 1, limit)) {
				return true;
			}
		}
	}
	
	for (int i = 0; i <= depth; ++i) {
		int nextSub = cur - arr[i];
		if (nextSub > 0) {
			if (iddfs(nextSub, depth + 1, limit)) {
				return true;
			}
		}
	}

	return false;
}

void solve() {
	int limit = 1;
	while (true) {
		
		if (iddfs(1, 0, limit)) {
			ans = limit;
			break;
		}


		++limit;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n != 1) {
			solve();
		}
		else {
			ans = 0;
		}
		cout << ans << '\n';
	}

}