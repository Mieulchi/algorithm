#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001];
int cnt[100001];
int t;

void solve() {
	queue<int> q;
	q.push(n);
	cnt[n] = 1;
	while (!q.empty()) {
		int size = q.size();
		int flag = 0;
		while (size--) {
			int f = q.front();
			q.pop();
			if (f == k) {
				flag = 1;
			}
			if (!visited[f]) {
				visited[f] = t + 1;
				if (visited[f + 1] == t) {
					cnt[f] += cnt[f + 1];
				}
				if (visited[f - 1] == t) {
					cnt[f] += cnt[f - 1];
				}
				if (f % 2 == 0 && visited[f / 2] == t) {
					cnt[f] += cnt[f / 2];
				}

				if (f + 1 < 100001 && !visited[f + 1]) {
					q.push(f + 1);
				}
				if (f - 1 >= 0 && !visited[f - 1]) {
					q.push(f - 1);
				}
				if (f * 2 < 100001 && !visited[f * 2]) {
					q.push(f * 2);
				}
			}

		}
		if (flag) {
			break;
		}
		t++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << t << '\n' << cnt[k];
}