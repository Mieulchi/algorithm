#include <iostream>
#include <queue>
using namespace std;

int n, k;
int ans;
int visited[200002];

void solve() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		int loc = q.front().first;
		int time = q.front().second;
		q.pop();
		if (visited[loc]) {
			continue;
		}
		visited[loc] = 1;
		if (loc == k) {
			ans = time;
			break;
		}
		else {
			if (loc + 1 <= 100000 && !visited[loc + 1]) {
				q.push({ loc + 1 , time + 1 });
			}
			if (loc - 1 >= 0 && !visited[loc - 1]) {
				q.push({ loc - 1 , time + 1 });
			}
			if (loc * 2 <= 100000 && !visited[loc * 2]) {
				q.push({ loc * 2 , time + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	solve();

	cout << ans;
}