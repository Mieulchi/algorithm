#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

struct coor {
	int index;
	int n;
};

map<int, int> graph[1001];
long long dist[1001];
int heapsize = 0;
coor heap[1001];

void init(int n) {
	for (int i = 0; i < n; i++) {
		dist[i] = -1;
	}
}

void insert(int index, int n) {
	heapsize++;
	int i = heapsize;
	while (heap[i / 2].n > n && i > 1) {
		heap[i] = heap[i / 2];
		i /= 2;
	}

	coor tmp;
	tmp.index = index;
	tmp.n = n;

	heap[i] = tmp;
}

int pop() {
	if (heapsize <= 0) {
		return -1;
	}
	coor result = heap[1];

	coor tmp = heap[heapsize--];
	int parent = 1, child = 2;
	while (child <= heapsize) {
		if ((child < heapsize) && (heap[child].n < heap[child + 1].n)) {
			child++;
		}
		if (tmp.n >= heap[child].n) {
			break;
		}
		else {
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
	}
	heap[parent] = tmp;

	return result.index;
}

void dijkstra(int from, int to, int n) {
	for (auto it = graph[from].begin(); it != graph[from].end(); it++) {
		if (graph[from][it->first] == -1) {
			graph[from][it->first] = 0;
		}
		dist[it->first] = graph[from][it->first];
		insert(it->first, dist[it->first]);
	}
	while (true) {
		int mindex = -1;
		mindex = pop();

		if (mindex == -1) {
			break;
		}

		for (auto it = graph[mindex].begin(); it != graph[mindex].end(); it++) {
			if (graph[mindex][it->first] == -1) {
				graph[mindex][it->first] = 0;
			}

			if (dist[it->first] == -1) {
				dist[it->first] = dist[mindex] + graph[mindex][it->first];
				insert(it->first, dist[it->first]);
			}
			else if (dist[it->first] != -1 && dist[mindex] + graph[mindex][it->first] < dist[it->first]) {
				dist[it->first] = dist[mindex] + graph[mindex][it->first];
				insert(it->first, dist[it->first]);
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	init(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c == 0) {
			c = -1;
		}
		if (graph[a - 1][b - 1]) {
			if (graph[a - 1][b - 1] > c) {
				graph[a - 1][b - 1] = c;
			}
		}
		else {
			graph[a - 1][b - 1] = c;
		}
	}

	int from, to;
	cin >> from >> to;

	dijkstra(from - 1, to - 1, n);



	cout << dist[to - 1] << '\n';

}