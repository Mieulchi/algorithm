#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e18

typedef long long ll;

int n;
vector<int> v[101];
vector<int> ansv[3];
int color[101];

void solve() {

	int start = 1;
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			queue<int> q;
			q.push(i);
			color[i] = start;
			ansv[start].push_back(i);

			while (!q.empty()) {
				int front = q.front();
				q.pop();

				int nextColor = 3 - color[front];

				for (int j = 0; j < v[front].size(); ++j) {
					int next = v[front][j];

					if (!color[next]) {
						color[next] = nextColor;
						q.push(next);
						ansv[nextColor].push_back(next);
					}
				}

			}
		}
		start = 3 - start;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, t;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		while (m--) {
			cin >> t;
			v[i].push_back(t);
			v[t].push_back(i);
		}
	}

	solve();

	for (int i = 1; i < 3; ++i) {
		cout << ansv[i].size() << '\n';
		sort(ansv[i].begin(), ansv[i].end());
		for (int j = 0; j < ansv[i].size(); ++j) {
			cout << ansv[i][j] << ' ';
		}
		cout << '\n';
	}
}