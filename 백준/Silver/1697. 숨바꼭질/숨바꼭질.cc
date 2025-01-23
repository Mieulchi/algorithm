#include <iostream>
#include <queue>
using namespace std;

int n, k;
int ans;
int visited[200002];

void solve() {
	queue<int> q;
	q.push(n);
	while (true) {
		queue<int> tmp;
		int flag = 0;
		while (!q.empty()) {
			int loc = q.front();
			q.pop();
			if (visited[loc]) {
				continue;
			}
			visited[loc] = 1;
			if (loc == k) {
				flag = 1;
				break;
			}
			else {
				if (loc + 1 <= 100000 && !visited[loc + 1]) {
					tmp.push(loc + 1);
				}
				if (loc - 1 >= 0 && !visited[loc - 1]) {
					tmp.push(loc - 1);
				}
				if (loc * 1 <= 100000 && !visited[loc * 2]) {
					tmp.push(loc * 2);
				}
			}
		}
		if (flag) {
			break;
		}
		q = tmp;
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	solve();

	cout << ans;
}