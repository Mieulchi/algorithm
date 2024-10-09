#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef struct {
	int vertex;
	int weight;
} MyPair;

vector<MyPair> graph[502];
vector<int> parent[501];

MyPair route[502];
int visited[501];

int minroute[501];

struct cmp {
	bool operator() (MyPair a, MyPair b) {
		return a.weight > b.weight;
	}
};

priority_queue<MyPair, vector<MyPair>, cmp> pq;

void init(int n) {
	for (int i = 0; i < n; i++) {
		route[i].weight = 0;
		route[i].vertex = 0;
		visited[i] = 0;
		parent[i].clear();
	}
}

void djikstra(int n, int from, int to, int flag) {
	for (int i = 0; i < graph[from].size(); i++) {
		if (graph[from][i].weight != 0) {
			route[graph[from][i].vertex] = graph[from][i];
			pq.push(graph[from][i]);
			if (flag && route[graph[from][i].vertex].weight == minroute[graph[from][i].vertex]) {
				parent[graph[from][i].vertex].push_back(from);
			}
		}
	}
	visited[from] = 1;

	while (!pq.empty()) {
		int mindex = pq.top().vertex;
		pq.pop();

		if (visited[mindex]) {
			continue;
		}

		for (int i = 0; i < graph[mindex].size(); i++) {
			if ((!route[graph[mindex][i].vertex].weight || route[graph[mindex][i].vertex].weight >= route[mindex].weight + graph[mindex][i].weight) && graph[mindex][i].weight && !visited[graph[mindex][i].vertex]) {
				route[graph[mindex][i].vertex].vertex = graph[mindex][i].vertex;
				route[graph[mindex][i].vertex].weight = route[mindex].weight + graph[mindex][i].weight;
				if (!visited[graph[mindex][i].vertex]) {
					pq.push(route[graph[mindex][i].vertex]);
				}

				if (flag && route[graph[mindex][i].vertex].weight == minroute[graph[mindex][i].vertex]) {
					parent[graph[mindex][i].vertex].push_back(mindex);
				}
			}
		}
		visited[mindex] = 1;
	}
}

int erasevisit[501];

void eraseGraph(int dest) {
	if (parent[dest].size() == 0) {
		return;
	}
	for (int i = 0; i < parent[dest].size(); i++) {
		for (int j = 0; j < graph[parent[dest][i]].size(); j++) {
			if (graph[parent[dest][i]][j].vertex == dest) {
				graph[parent[dest][i]][j].weight = 0;
				if (!erasevisit[parent[dest][i]]) {
					eraseGraph(parent[dest][i]);
				}
			}
		}
	}
	erasevisit[dest] = 1;
}

int main() {
	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}
		int from, to;
		cin >> from >> to;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			MyPair tmppair;
			tmppair.vertex = b;
			tmppair.weight = c;

			graph[a].push_back(tmppair);
		}

		djikstra(n, from, to, 0);
		
		for (int i = 0; i < n; i++) {
			minroute[i] = route[i].weight;
		}
		init(n);

		djikstra(n, from, to, 1);

		eraseGraph(to);

		init(n);

		djikstra(n, from, to, 0);

		int result = route[to].weight;
		if (result == 0) {
			result = -1;
		}
		cout << result << '\n';

		for (int i = 0; i < n; i++) {
			graph[i].clear();
			parent[i].clear();
			minroute[i] = 0;
			erasevisit[i] = 0;
		}
		init(n);
	}
}