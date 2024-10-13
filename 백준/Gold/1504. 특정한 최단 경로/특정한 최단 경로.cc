#include <iostream>
#include <climits>
using namespace std;

int graph[801][801];

int visited[801];
int dist[801];

void clearDistance(int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
		dist[i] = 0;
	}
}

int Dijkstra(int from, int to, int n) {
	visited[from] = 1;
	for (int i = 0; i < n; i++) {
		if (graph[from][i] != 0 && i != from) {
			dist[i] = graph[from][i];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int min = INT_MAX;
		int mindex = -1;
		//최소 정점 고르기
		for (int j = 0; j < n; j++) {
			if (visited[j] == 0 && dist[j] != 0 && dist[j] < min) {
				min = dist[j];
				mindex = j;
			}
		}
		if (mindex == -1) {
			break;
		}

		visited[mindex] = 1;

		//from에서의 거리정보 수정
		for (int j = 0; j < n; j++) {
			if (graph[mindex][j] != 0 && j != from) {
				if (dist[j] == 0) {
					dist[j] = dist[mindex] + graph[mindex][j];
				}
				else {
					if (dist[j] > dist[mindex] + graph[mindex][j]) {
						dist[j] = dist[mindex] + graph[mindex][j];
					}
				}
			}
		}
		visited[mindex] = 1;
	}

	int result = dist[to];
	clearDistance(n);
	return result;
}
 
int main() {
	
	int n, e, v1, v2;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = c;
		graph[b - 1][a - 1] = c;
	}

	cin >> v1 >> v2;

	v1--;
	v2--;
	int route1, route2, route3, route4;
	int defaultroute;
	defaultroute = Dijkstra(v1, v2, n);

	route1 = Dijkstra(0, v1, n);
	route2 = Dijkstra(0, v2, n);
	route3 = Dijkstra(n - 1, v1, n);
	route4 = Dijkstra(n - 1, v2, n);

	if (v1 == 0 || v2 == n - 1) {
		int result = 0;
		if (v1 == 0 && v2 == n - 1) {
			if (defaultroute == 0) {
				result = -1;
			}
			else {
				result = defaultroute;
			}
		}
		else {
			if (v1 == 0) {
				if (route4 == 0) {
					result = -1;
				}
			}
			if (v2 == n - 1) {
				if (route1 == 0) {
					result = -1;
				}
			}

			if (defaultroute == 0) {
				result = -1;
			}
			else {
				if (result != -1) {
					result = defaultroute + route1 + route4;
				}
			}
		}

		cout << result;
	}
	else {
		if (route1 + route4 > route2 + route3) {
			if (route2 == 0 || route3 == 0 || defaultroute == 0) {
				if (route1 != 0 && route4 != 0 && defaultroute != 0) {
					cout << route1 + route4 + defaultroute;
				}
				else {
					cout << -1;
				}
			}	
			else {
				cout << route2 + route3 + defaultroute;
			}
		}
		else {
			if (route1 == 0 || route4 == 0 || defaultroute == 0) {
				if (route2 != 0 && route3 != 0 && defaultroute != 0) {
					cout << route2 + route3 + defaultroute;
				}
				else {
					cout << -1;
				}
			}
			else {
				cout << route1 + route4 + defaultroute;
			}
		}
	}
}