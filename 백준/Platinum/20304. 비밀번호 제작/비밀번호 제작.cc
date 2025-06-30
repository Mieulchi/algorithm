#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q;
int visited[1000001];
int ans;
int cnt;

void bfs(int bitmask) {
	int i = 0;
	while (true) {
		if ((1 << i) > n) {
			break;
		}
		int target;
		if ((bitmask >> i) & 1) {
			target = bitmask - (1 << i);
		}
		else {
			target = bitmask + (1 << i);
		}
		if (target <= n && !visited[target]) {
			q.push(target);
		}
		i++;
	}
}

void solve() {
	while (!q.empty()) {
		queue<int> tmp;
		while (!q.empty()) {
			tmp.push(q.front());
			q.pop();
		}
	
		while (!tmp.empty()) {
			int front = tmp.front();
			tmp.pop();
			if (visited[front]) {
				continue;
			}
			visited[front] = 1;
			cnt++;
			bfs(front);
		}
		if (cnt == n + 1) {
			break;
		}
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		q.push(tmp);
	}
	solve();
	cout << ans;
}