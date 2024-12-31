#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int v, e;

vector<int> vec[20001];
int graph[20001];

string ans;

void dfs(int s) {
    bool res = true;

    if (graph[s] == 1) {
        for (int i = 0; i < vec[s].size(); i++) {
            if (!graph[vec[s][i]]) {
                graph[vec[s][i]] = 2;
                dfs(vec[s][i]);
            }
            else {
                if (graph[vec[s][i]] == graph[s]) {
                    ans = "NO";
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < vec[s].size(); i++) {
            if (!graph[vec[s][i]]) {
                graph[vec[s][i]] = 1;
                dfs(vec[s][i]);
            }
            else {
                if (graph[vec[s][i]] == graph[s]) {
                    ans = "NO";
                    break;
                }
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
        if (vec[i].size()) {
            if (!graph[i]) {
                graph[i] = 1;   
            }
            dfs(i);
            if (ans == "NO") {
                break;
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        vec[i].clear();
    }
    memset(graph, 0, sizeof(graph));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ans = "YES";
        cin >> v >> e;
        solve();

        cout << ans << '\n';
    }
}