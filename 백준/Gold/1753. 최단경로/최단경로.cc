#include <iostream>
#include <climits>
#include <map>
using namespace std;

struct coor {
	int index;
	int n;
};

map<int, int> m[20001];

coor heap[300001];
int heapsize = 0;

int dist[20001];
int visited[20001];

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
		if ((child < heapsize) && (heap[child].n > heap[child + 1].n)) {
			child++;
		}
		if (tmp.n <= heap[child].n) {
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

void dijkstra(int from) {
	visited[from] = 1;
	//최초 정점에서 방문할정점 heap에 다 넣고
	for (auto it = m[from].begin(); it != m[from].end(); it++) {
		dist[it->first] = m[from][it->first];
		insert(it->first, dist[it->first]);
	}
	while (heapsize > 0) {
		int mindex = -1;
		//최소정점 뽑고
		mindex = pop();


		//방문할 정점이 중복될수있음, 이미 방문햇으면 그냥 큐에서 제거하고 넘어감
		if (!visited[mindex]) {
			visited[mindex] = 1;

			for (auto it = m[mindex].begin(); it != m[mindex].end(); it++) {
				if (dist[it->first] == 0 && it->first != from) {
					dist[it->first] = dist[mindex] + m[mindex][it->first];
					insert(it->first, dist[it->first]);
				}
				else {
					if (dist[mindex] + m[mindex][it->first] < dist[it->first]) {
						dist[it->first] = dist[mindex] + m[mindex][it->first];
						insert(it->first, dist[it->first]);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	int from;
	cin >> from;
	from--;

	//node - map 
	//ex ) 1 2 3 이면
	// node 0 - map(node 1, weight 3)으로 저장, 같은 간선이면 값 비교하고 바꿔줌
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (m[a - 1][b - 1]) {
			if (m[a - 1][b - 1] > c) {
				m[a - 1][b - 1] = c;
			}
		}
		else {
			m[a - 1][b - 1] = c;
		}

	}

	dijkstra(from);

	for (int i = 0; i < v; i++) {
		if ((i != from && !dist[i])) {
			cout << "INF" << '\n';
		}
		else if (i == from) {
			cout << 0 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}