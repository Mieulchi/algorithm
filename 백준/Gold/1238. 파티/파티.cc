#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<int, int> graph[1001];

int toparty[1001][1001];
int tohome[1001];
int visited[1001];

void initVisit() {
	for (int i = 0; i < 1000; i++) {
		visited[i] = 0;
	}
}

int glob;

struct cmp {
	bool operator() (int a, int b) {
		return toparty[glob][a] > toparty[glob][b];
	}
};

priority_queue<int, vector<int>, cmp> pq;

void djikstraToParty(int n, int from, int to) {
	visited[from] = 1;
	glob = from;
	int mindex = 0;
	for (auto it = graph[from].begin(); it != graph[from].end(); it++) {
		if (graph[from][it->first]) {
			toparty[from][it->first] = graph[from][it->first]; 
			pq.push(it->first);
		}
	}

	while (!pq.empty()) {
		mindex = pq.top();
		pq.pop();
		if (visited[mindex]) {
			continue;
		}
		
		for (auto it = graph[mindex].begin(); it != graph[mindex].end(); it++) {
			if (!toparty[from][it->first] && graph[mindex][it->first] && it->first != from) {
				toparty[from][it->first] = toparty[from][mindex] + graph[mindex][it->first];
				pq.push(it->first);
			}
			else if (toparty[from][it->first] > toparty[from][mindex] + graph[mindex][it->first] && it->first != from) {
				toparty[from][it->first] = toparty[from][mindex] + graph[mindex][it->first];
				pq.push(it->first);
			}
		}
		visited[mindex] = 1;
	}
}

void djikstraToHome(int n, int from) {
	int mindex = 0;
	glob = from;
	for (auto it = graph[from].begin(); it != graph[from].end(); it++) {
		tohome[it->first] = graph[from][it->first];
		pq.push(it->first);
	}

	while (!pq.empty()) {
		mindex = pq.top();
		pq.pop();

		if (visited[mindex]) {
			continue;
		}

		for (auto it = graph[mindex].begin(); it != graph[mindex].end(); it++) {
			if (!tohome[it->first] && it->first != from) {
				tohome[it->first] = tohome[mindex] + graph[mindex][it->first];
				pq.push(it->first);
			}
			else if (tohome[it->first] && tohome[it->first] > tohome[mindex] + graph[mindex][it->first] && it->first != from) {
				tohome[it->first] = tohome[mindex] + graph[mindex][it->first];
				pq.push(it->first);
			}
		}
		visited[mindex] = 1;
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int r, c, t;
		cin >> r >> c >> t;
		graph[r - 1][c - 1] = t;
	}
	for (int i = 0; i < n; i++) {
		djikstraToParty(n, i, x - 1);
		initVisit();

	}

	djikstraToHome(n, x - 1);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < toparty[i][x - 1] + tohome[i]) {
			max = toparty[i][x - 1] + tohome[i];
		}
	}
	cout << max;
}