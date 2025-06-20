#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> arr[101][101];
int lighted[101][101];
int visited[101][101];
int ans;

void solve() {
	queue<pair<int,int>> q;
	q.push({ 1,1 });
	lighted[1][1] = 1;
	ans++;
	while (!q.empty()) {
		queue<pair<int, int>> tmp;
		while (!q.empty()) {
			pair<int, int> front = q.front();
			int r = front.first;
			int c = front.second;
			visited[r][c] = 1;
			q.pop();

			//일단 불을 다 켜
			for (int i = 0; i < arr[r][c].size(); i++) {
				int r1 = arr[r][c][i].first;
				int c1 = arr[r][c][i].second;
				if (!lighted[r1][c1]) {
					ans++;
					lighted[r1][c1] = 1;
					//불켯는데 간적있으면 갈수있으니까 큐에 넣어
					if (visited[r1][c1]) {
						tmp.push({ r1, c1 });
					}
				}
			}

			//상하좌우를 돌면서 불켜진곳을 가
			if (r + 1 <= n) {
				if (lighted[r + 1][c] && !visited[r + 1][c]) {
					tmp.push({ r + 1, c });
				}
				visited[r + 1][c] = 1;
			}
			if (r - 1 >= 1) {
				if (lighted[r - 1][c] && !visited[r - 1][c]) {
					tmp.push({ r - 1, c });
				}
				visited[r - 1][c] = 1;
			}
			if (c + 1 <= n) {
				if (lighted[r][c + 1] && !visited[r][c + 1]) {
					tmp.push({ r, c + 1 });
				}
				visited[r][c + 1] = 1;
			}
			if (c - 1 >= 1) {
				if (lighted[r][c - 1] && !visited[r][c - 1]) {
					tmp.push({ r, c - 1 });
				}
				visited[r][c - 1] = 1;
			}
		}
		q = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int x, y, a, b;
	while (m--) {
		cin >> x >> y >> a >> b;
		arr[x][y].push_back({ a,b });
	}
	solve();
	cout << ans;
}