#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct State {
    int u, tm, t;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> cycle(T);
    for (int i = 0; i < T; i++) {
        cin >> cycle[i];
    }

    // remT[tm] = time to wait from tm until cycle hits N
    vector<int> remT(T, INF);
    for (int tm = 0; tm < T; tm++) {
        for (int d = 0; d < T; d++) {
            if (cycle[(tm + d) % T] == N) {
                remT[tm] = d;
                break;
            }
        }
    }

    // visited[node][tm]
    vector<vector<bool>> visited(N + 1, vector<bool>(T, false));
    queue<State> q;
    visited[1][0] = true;
    q.push({1, 0, 0});

    int ans = INF;
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        int u = cur.u;
        int tm = cur.tm;
        int tme = cur.t;
        if (tme >= ans) continue;

        // 도보로 N 도착
        if (u == N) {
            ans = min(ans, tme);
            continue;
        }
        // 현재 시점에 만남 가능
        if (cycle[tm] == u && remT[tm] < INF) {
            ans = min(ans, tme + remT[tm]);
            continue;
        }

        int ntm = (tm + 1) % T;
        // 대기
        if (!visited[u][ntm]) {
            visited[u][ntm] = true;
            q.push({u, ntm, tme + 1});
        }
        // 이동
        for (int v : graph[u]) {
            if (!visited[v][ntm]) {
                visited[v][ntm] = true;
                q.push({v, ntm, tme + 1});
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}
