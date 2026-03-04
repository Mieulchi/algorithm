#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define MOD 1000000007
typedef long long ll;

ll n, m;
string ans = "NO";
map<ll, int> visited;

void solve() {

	queue<ll> q;
	q.push(n);


	while (!q.empty()) {
		ll front = q.front();
		q.pop();

		if (visited[front]) {
			continue;
		}
		visited[front] = 1;
		if (front == m) {
			ans = "YES";
			break;
		}

		q.push(front / 2);

		if (front % 2) {
			q.push(front / 2 + 1);
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve();
	cout << ans;
}