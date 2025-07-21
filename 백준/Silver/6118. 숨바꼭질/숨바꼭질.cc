#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<int> v[20001];
int visited[20001];
int a, b, c;

void solve() {
	queue<int> q;
	q.push(1);
	int time = 1;
	while (!q.empty()) {
		int size = q.size();
		int flag = 1;
		while (size--) {
			int front = q.front();
			q.pop();
			if (!visited[front]) {
				flag = 0;
				visited[front] = time;
				for (int i = 0; i < v[front].size(); i++) {
					if (!visited[v[front][i]]) {
						q.push(v[front][i]);
					}
				}
			}
		}
		if (flag) {
			time--;
		}
		time++;
	}
	b = time - 1;
	for (int i = 1; i <= n; i++) {
		if (!a && visited[i] == b) {
			a = i;
		}
		if (visited[i] == b) {
			c++;
		}
	}
	b--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();
	cout << a << ' ' << b << ' ' <<  c;
}