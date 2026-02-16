#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000007


int n, root, ans;
vector<int> v[1001];
int weight[1001];
int dp[1001][1001];

int find(int parent, int node, int special) {

	int w = weight[node];
	int sum1 = w - special, sum2 = w;

	if (dp[node][special]) {
		return dp[node][special];
	}

	//sum1 == present node is not special
	for (int i = 0; i < v[node].size(); ++i) {
		int next = v[node][i];

		if (next != parent) {
			sum1 += find(node, next, special);
		}
	}

	//sum2 == present node is special
	for (int i = 0; i < v[node].size(); ++i) {
		int next = v[node][i];

		if (next != parent) {
			sum2 += find(node, next, w);
		}
	}


	if (sum1 == sum2 && !sum1) {
		dp[node][special] = w - special;
	}
	else {
		dp[node][special] = min(sum1, sum2);
	}

	return dp[node][special];
}

void solve() {

	ans = weight[root];
	for (int i = 0; i < v[root].size(); ++i) {
		ans += find(root, v[root][i], weight[root]);
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> root;

	for (int i = 1; i <= n; ++i) {
		cin >> weight[i];
	}

	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	cout << ans;
}
