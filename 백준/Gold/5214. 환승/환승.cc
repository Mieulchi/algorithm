#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, M;
vector<int> tube[1000];
int visited[100001];
int visitedTube[1000];
int ans;

void solve() {
	queue<int> q;
	for (int i = 0; i < M; i++) {
		sort(tube[i].begin(), tube[i].end());
		if (binary_search(tube[i].begin(), tube[i].end(), 1)) {
			q.push(i);
		}
	}
	visited[1] = 1;
	int time = 1;
	while (!q.empty()) {
		int size = q.size();
		queue<int> tmp;
		while (size--) {
			int front = q.front();
			q.pop();
			if (!visitedTube[front]) {
				visitedTube[front] = 1;
				for (int i = 0; i < tube[front].size(); i++) {
					if (!visited[tube[front][i]]) {
						tmp.push(tube[front][i]);
					}
				}
			}
		}
		while (!tmp.empty()) {
			int front = tmp.front();
			tmp.pop();
			if (!visited[front]) {
				visited[front] = 1;
				for (int i = 0; i < M; i++) {
					if (!visitedTube[i]) {
						if (binary_search(tube[i].begin(), tube[i].end(), front)) {
							q.push(i);
						}
					}
				}
			}
		}
		if (!visited[N]) {
			time++;
		}
		else {
			ans = time + 1;
			break;
		}
	}
if (!ans) {
	ans = -1;
}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> M;

	for (int i = 0; i < M; i++) {
		int tmp;
		for (int j = 0; j < K; j++) {
			cin >> tmp;
			tube[i].push_back(tmp);
		}
	}
	if (N > 1) {
		solve();
	}
	else {
		ans = 1;
	}
	cout << ans;
}