#include <iostream>
#include <queue>
using namespace std;

int n, a, b, m, ans;
vector<int> v[101];
int visited[101];

void solve() {
    queue<int> q;
    q.push(a);

    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int front = q.front();
            if (front == b) {
                ans = cnt;
                break;
            }
            q.pop();
            if (!visited[front]) {
                visited[front] = 1;
                for (int i = 0; i < v[front].size(); ++i) {
                    if (!visited[v[front][i]]) {
                        q.push(v[front][i]);
                    }
                }
            }
        }
        if (ans) {
            break;
        }
        ++cnt;
    }
    if (!ans) {
        ans = -1;
    }
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