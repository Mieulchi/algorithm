#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int n;
int dari[10001];
int visited[10001];
int a, b;

int ans;

void solve() {
	ans = -1;
	int count = 1;
	while (!q.empty()) {
		int size = q.size();

		for (int s = 0; s < size; s++) {
			int start = q.front();
			int interval = dari[start];
			q.pop();

			int i;
			if (interval < 0) {
				interval *= -1;
			}
			for (i = start; i <= n; i += interval) {
				if (i == b) {
					ans = count;
					return;
				}
				if (!visited[i]) {
					visited[i] = 1;
					q.push(i);
				}
			}
			if (i == b) {
				break;
			}

			for (i = start; i > 0; i -= interval) {
				if (i == b) {
					ans = count;
					return;
				}
				if (!visited[i]) {
					visited[i] = 1;
					q.push(i);
				}
			}
			if (i == b) {
				return;
			}
		}
		count++;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> dari[i];
	}
	cin >> a >> b;
	if (a == b) {
		ans = 0;
	}
	else {
		q.push(a);
		solve();
	}

	cout << ans;
}