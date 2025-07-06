#include <iostream>
#include <queue>
using namespace std;

int n;
int visited[51];
int arr[6];
vector<int> v[51];
string ans;


void f(int node) {
	queue<int> q;
	for (int i = 0; i < 4; i++) {
		if (!visited[v[node][i]]) {
			q.push({ v[node][i] });
		}
	}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		visited[front] = 1;
		queue<int> tmp;
		tmp.push(front);
		while (true) {
			int front = tmp.front();
			tmp.pop();
			visited[front] = 1;
			if (v[front].size() == 4) {
				arr[2] = front;
				break;
			}
			else if (v[front].size() == 3) {
				if (!arr[1]) {
					arr[1] = front;
					break;
				}
				else {
					arr[3] = front;
					break;
				}
			}
			for (int i = 0; i < v[front].size(); i++) {
				if (!visited[v[front][i]]) {
					tmp.push(v[front][i]);
				}
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 1) {
			arr[5] = i;
			break;
		}
	}
	queue<int> q;
	q.push(arr[5]);
	while (true) {
		int front = q.front();
		q.pop();
		visited[front] = 1;
		if (v[front].size() == 4) {
			arr[4] = front;
			break;
		}
		for (int i = 0; i < v[front].size(); i++) {
			if (!visited[v[front][i]]) {
				q.push(v[front][i]);
			}
		}
	}
	f(arr[4]);
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 3 && arr[1] != i && arr[3] != i) {
			arr[0] = i;
		}
	}

	if (arr[3] < arr[1]) {
		int tmp = arr[1];
		arr[1] = arr[3];
		arr[3] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b;
	for (int i = 0; i < n + 3; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve();

	for (int i = 0; i < 6; i++) {
		cout << arr[i] << ' ';
	}
} 