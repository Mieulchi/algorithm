#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pp;

int n, k, ans;
int visited[100002];

void solve() {
	for (int i = 0; i <= 100000; ++i) {
		visited[i] = -1;
	}

	int time = 0;

	queue<int> q;
	q.push(n);
	visited[n] = n;

	while (!q.empty()) {
		int size = q.size();

		while (size--) {

			int front = q.front();
			q.pop();

			if (front == k) {
				ans = time;
				break;
			}

			if (front + 1 <= 100000 && visited[front + 1] == -1) {
				visited[front + 1] = front;
				q.push(front + 1);
				
			}
			if (front - 1 >= 0 && visited[front - 1] == -1) {
				visited[front - 1] = front;
				q.push(front - 1);
			}
			if (front * 2 <= 100000 && visited[front * 2] == -1) {
				visited[front * 2] = front;
				q.push(front * 2);
			}
		}
		++time;

		if (ans) {
			break;
		}
	}

}

void print(int node) {
	if (node != n) {
		print(visited[node]);
	}
	cout << node << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	solve();
	cout << ans << '\n';
	print(k);
}