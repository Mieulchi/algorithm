#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int xs, ys, xe, ye;
pair<int, int> v[8];
long long  graph[8][8];
long long dist[8];
int visited[8];
long long ans;

void solve() {
    for (int i = 0; i < 8; ++i) {
        for (int j = i; j < 8; ++j) {
            if (i != j) {
                long long dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                if (graph[i][j]) {
                    graph[i][j] = min(graph[i][j], dist);
                    graph[j][i] = min(graph[j][i], dist);
                }
                else {
                    graph[i][j] = dist;
                    graph[j][i] = dist;
                }
            }
        }
    }

    dist[0] = 0;
    visited[0] = 1;

    for (int i = 1; i < 8; ++i) {
        dist[i] = graph[0][i];
    }

    int cnt = 7;

    while (cnt--) {
        long long m = INF;
        int idx = 0;

        for (int i = 1; i < 8; ++i) {
            if (!visited[i] && dist[i] < m) {
                m = dist[i];
                idx = i;
            }
        }
        visited[idx] = 1;
        for (int i = 0; i < 8; ++i) {
            dist[i] = min(dist[i], dist[idx] + graph[idx][i]);
        }
    }
    ans = dist[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xs >> ys >> xe >> ye;
    v[0] = { xs, ys };
    v[1] = { xe, ye };
    graph[0][1] = graph[1][0] = abs(xs - xe) + abs(ys - ye);

    for (int i = 2; i < 8; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = { a, b };
        if (i % 2) {
            graph[i][i - 1] = 10;
            graph[i - 1][i] = 10;
        }
    }
    solve();
    cout << ans;
}