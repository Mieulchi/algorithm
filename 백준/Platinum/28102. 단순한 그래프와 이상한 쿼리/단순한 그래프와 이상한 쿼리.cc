#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e18

typedef long long ll;

int n, m, q;
vector<int> v[100001];
int parent[100001];
int color[100001];
int bPartial[100001];

string ans;

/*
	1) k가 홀수 -> 배수가 홀, 짝, 홀, 짝 -> 간선이	 짝이든 홀이든 연결만 된다면 결국 홀,짝 암거나 서로 곱하면 되니까.
	2) k가 짝수 -> 짝수만 나옴 -> 거리가 짝수면 OK 거리가 홀수면? 홀수 싸이클이 필요
	홀수 사이클이 있으면 반드시 홀-짝을 만들 수 있다. 이분 그래프에는 홀수 싸이클이 생기지 않는다.

	->두 점이 속한 그래프가 동일하고, 이분그래프가 아닌 경우 -> 그냥 무조건 가능
	이분그래프인 경우 -> 같은 그룹이면 가능, 아니면 안됨

*/

int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa != pb) {
		parent[pa] = pb;
	}
}

//이분그래프가 아니라면 해당 그래프 전부 -1 기록, 이분그래프라면 1/2로 구분
bool make_graph(int node) {
	queue<int> q;

	q.push(node);
	color[node] = 1;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (find(node) != find(front)) {
			merge(node, front);
		}
		int nextColor = 3 - color[front];

		for (int i = 0; i < v[front].size(); ++i) {
			int next = v[front][i];

			if (!color[next]) {
				color[next] = nextColor;
				q.push(next);
			}
			else {
				if (color[next] != nextColor) {
					return false;
				}
			}
		}
	}
	return true;
}

void fill_graph(int node) {
	queue<int> q;

	q.push(node);
	color[node] = -1;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (find(node) != find(front)) {
			merge(node, front);
		}

		for (int i = 0; i < v[front].size(); ++i) {
			int next = v[front][i];

			if (color[next] != -1) {
				color[next] = -1;
				q.push(next);
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			bool flag = make_graph(i);
			if (!flag) {
				fill_graph(i);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> q;

	int a, b, c, k;
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();
	while (q--) {
		cin >> a >> b >> k;

		//홀수
		if (k % 2) {
			ans = find(a) == find(b) ? "Yes" : "No";
		}
		else {
			if (find(a) == find(b)) {
				if (color[a] == -1) {
					ans = "Yes";
				}
				else {
					if (color[a] == color[b]) {
						ans = "Yes";
					}
					else {
						ans = "No";
					}
				}
			}
			else {
				ans = "No";
			}
		}

		cout << ans << '\n';
	}

}