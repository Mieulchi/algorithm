#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[1000][1000];
int visited[1000][1000];

typedef pair<int, pair<int, int>> corn;

struct cmp {
	bool operator()(corn c1, corn c2) {
		return c1.first < c2.first;
	}
};

priority_queue<corn, vector<corn>, cmp> pq;

void solve() {
	while (k) {
		corn front = pq.top();
		pq.pop();
		int r = front.second.first;
		int c = front.second.second;
		if (!visited[r][c]) {
			k--;
			visited[r][c] = 1;
			cout << r + 1 << ' ' << c + 1 << '\n';
			if (r + 1 < n && !visited[r + 1][c]) {
				pq.push({ arr[r + 1][c], {r + 1, c} });
			}
			if (r - 1 >= 0 && !visited[r - 1][c]) {
				pq.push({ arr[r - 1][c], {r - 1, c} });
			}
			if (c + 1 < m && !visited[r][c + 1]) {
				pq.push({ arr[r][c + 1], {r, c + 1} });
			}
			if (c - 1 >= 0 && !visited[r][c - 1]) {
				pq.push({ arr[r][c - 1], {r, c - 1} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				pq.push({ arr[i][j], {i, j }});
			}
		}
	}
	cin >> k;
	solve();
}