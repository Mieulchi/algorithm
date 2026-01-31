#include <iostream>
#include <vector>
using namespace std;

int n, a, b, m, ans;
vector<int> v[101];
int visited[101];

void dfs(int node, int depth) {
    if (visited[node]) {
        return;
    }
    visited[node] = 1;
    if (node == b) {
        if (!ans || depth < ans) {
            ans = depth;
        }
        visited[node] = 0;
        return;
    }
    for (int i = 0; i < v[node].size(); ++i) {
        dfs(v[node][i], depth + 1);
    }
    visited[node] = 0;
}

void solve() {
    visited[a] = 1;
    for (int i = 0; i < v[a].size(); ++i) {
        dfs(v[a][i], 1);
    }
    if (!ans) { ans = -1; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> a >> b;
    cin >> m;
    while(m--) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    solve();
    cout << ans;
}