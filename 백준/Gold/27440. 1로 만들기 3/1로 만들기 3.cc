#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long x;
map<long long, int> visited;
int ans;

void solve() {
	queue<long long> q;
	q.push(x);
	ans = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			long long front = q.front();
			q.pop();
			if (front == 1) {
				return;
			}
			if (visited[front]) {
				continue;
			}
			visited[front] = 1;

			if (front % 3 == 0) {
				q.push({ front / 3 });
			}
			if (front % 2 == 0) {
				q.push({ front / 2 });
			}
			if (front - 1 > 0) {
				q.push(front - 1);
			}
		}
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x;
	solve();
	cout << ans;
}