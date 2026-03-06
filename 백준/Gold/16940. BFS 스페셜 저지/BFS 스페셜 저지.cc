#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pp;

int n, ans = 1;

int visited[100001];
vector<int> v[100001];
unordered_map<int, int> um;

queue<int> seq;

void solve() {

	queue<int> q;
	q.push(1);
	visited[1] = 1;
	if (seq.front() != 1) {
		ans = 0;
		return;
	}
	seq.pop();

	while (!q.empty()) {

		int front = q.front();
		q.pop();

		queue<int> tmp;

		int cnt = 0;
		for (int i = 0; i < v[front].size(); ++i) {
			int next = v[front][i];
			if (!visited[next]) {
				visited[next] = 1;
				++cnt;
			}
		}
		for (int i = 0; i < cnt; ++i) {
			int next = seq.front();
			seq.pop();
			q.push(next);
			if (!visited[next]) {
				ans = 0;
				break;
			}
		}

		if (!ans) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		cin >> a;
		seq.push(a);
	}

	solve();

	cout << ans;
}